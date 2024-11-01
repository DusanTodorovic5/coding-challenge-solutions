#include <iostream>
# include <vector>

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        static const int modulo = std::pow(10, 9) + 7;

        if (n * k < target) {
            return 0;
        }

        std::vector<std::vector<int>> ways(n + 1, std::vector<int>(target + 1, 0));
        ways[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            int outer = std::min(i * k, target);
            for (int j = i; j <= outer; j++) {
                int inner = std::min(k, j);
                for (int l = 1;l <= inner; l++) {
                    ways[i][j] = (ways[i][j] + ways[i - 1][j - l]) % modulo;
                }
            }
        }

        return ways[n][target];
    }
};

int main(int, char**){
    std::cout << "Hello, from dice_rolls!\n";
}
