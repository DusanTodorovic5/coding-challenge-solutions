# Problem

You have `n` dice, and each die has `k` faces numbered from `1` to `k`.

> Given three integers `n`, `k`, and `target`, return the number of possible ways (out of the `k^n` total ways) to roll the dice, so the sum of the face-up numbers equals `target`. Since the answer may be too large, return it modulo `10^9 + 7`.

# Approach

The idea is to iterate trough each way and aggregate it in last.

# Code
```cpp
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
```