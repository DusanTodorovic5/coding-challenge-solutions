# Problem

Given a string `path`, where `path[i] = 'N'`, `'S'`, `'E'` or `'W'`, each representing moving one unit north, south, east, or west, respectively. You start at the origin `(0, 0)` on a 2D plane and walk on the `path` specified by `path`.

Return `true` if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return `false` otherwise.

# Approach
Idea is to have map of all points we have been to. We also need to know current coordinates. For each character, we move current coordinates and check if we were already there.

# Complexity
- Time complexity:
O(n)

- Space complexity:
O(n)

# Code
```cpp
class Solution {
public:
    bool isPathCrossing(std::string path) {
        std::unordered_map<int,std::unordered_map<int, bool>>  visited_path;

        int current_x = 0;
        int current_y = 0;
        visited_path[current_x][current_y] = true;
        for (char c : path) {
            switch (c) {
                case 'N': current_y++; break;
                case 'S': current_y--; break;
                case 'E': current_x++; break;
                case 'W': current_x--; break;
            }

            if (std::exchange(visited_path[current_x][current_y], true)) {
                return true;
            }
        }

        return false;
    }
};
```