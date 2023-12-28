#include <iostream>
#include <string>
#include <queue>
#include <functional>

class Solution {
public:
    int getLengthOfOptimalCompression(std::string s, int k) {
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

int main(int, char**){
    std::cout << Solution().getLengthOfOptimalCompression("aaabcccd", 2) << std::endl;
}
