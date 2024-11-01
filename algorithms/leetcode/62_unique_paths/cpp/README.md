# Problem

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

# Approach
The idea is to simple. As we can move only right and down, we can calculate the number of paths for that field as sum of number of paths for field left and up. The first column and row always have only 1 path. 
The optimization that is done here, to make things a bit faster and to save on memory, is to memorize only 1 row. This way, we calculate new value as current + left field.

# Complexity
- Time complexity:
O(n*m)

- Space complexity:
O(n)

# Code
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < 2 || n < 2) {
            return 1;
        }

        // Allocate memory for n integers, all with value 1
        std::vector<int> grid_row(n, 1);

        // No need to memorize each row, only the current one
        // because the sum is current + left, where row[0] is always 1
        while (--m) {
            for (int i = 1; i < n; i++) {
                grid_row[i] += grid_row[i - 1];
            }
        }

        // We return last element in array, that is actually our value
        return grid_row[n - 1];
    }
};
```