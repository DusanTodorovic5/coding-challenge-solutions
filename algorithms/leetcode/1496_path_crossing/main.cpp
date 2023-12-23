#include <iostream>
#include <unordered_map>

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

int main(int, char**){
    std::cout << "Hello, from path_crossing!\n";
}
