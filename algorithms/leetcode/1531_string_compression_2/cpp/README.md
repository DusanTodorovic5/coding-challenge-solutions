# Approach
Idea is to go with dp, for each character, we assume that we do not delete it, and we can put same value as last character. Then, once we enter the inner most for loop, we iterate trough each character and concat all the same ones.

# Complexity
- Time complexity:
O(n*k)

- Space complexity:
O(n*k)

# Code
```cpp
class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        std::vector<std::vector<int>> dp(s.length() + 1, std::vector<int>(k + 1, 0));

        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = j > 0 ? dp[i + 1][j - 1] : INT_MAX;

                int deletions = j;
                int count = 0;

                for (int l = i; l < s.size() && deletions >= 0; l++) {
                    if (s[l] == s[i]) {
                        count++;

                        int lengthOfCount = count == 1 ? 1 : 2 + std::log10(count);
                        dp[i][j] = std::min(dp[i][j], lengthOfCount + dp[l + 1][deletions]);
                    }
                    else {
                        deletions--;
                    }
                }
            }
        }

        return dp[0][k];
    }
};
```