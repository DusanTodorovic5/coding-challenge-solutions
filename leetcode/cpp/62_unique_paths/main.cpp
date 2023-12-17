#include <iostream>
#include <vector>

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

int main(int, char**){
    Solution sol;

    std::cout << sol.uniquePaths(3, 7) << std::endl;
    system("pause");
}
