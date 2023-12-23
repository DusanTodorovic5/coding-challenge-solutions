#include <iostream>
#include <utility>

class Solution {
public:
    int maxScore(std::string s) {
        int leftZeros = s[0] == '0';
        int rightOnes = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') { 
                rightOnes++;
            }
        }

        int max_split_score = leftZeros + rightOnes;
        for (int i = 0;i < s.length() - 1;i++) {
            if (s[i] == '0') {
                leftZeros++;
            } else {
                rightOnes--;
            }

            max_split_score = std::max(max_split_score, leftZeros + rightOnes);
        }

        return max_split_score;
    }
};

int main() {
    Solution().maxScore("11100");
}