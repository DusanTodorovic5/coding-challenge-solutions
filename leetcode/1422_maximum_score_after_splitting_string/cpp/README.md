# Problem

Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

# Approach
Idea is to count all ones in string, afterwards, we iterate trough the string and if its 0, we increment zero counter, else we remove from ones counter.

# Complexity
- Time complexity:
O(n)

- Space complexity:
O(1)

# Code
```cpp
class Solution {
public:
    int maxScore(string s) {
        int leftZeros = s[0] == '0';
        int rightOnes = 0;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '1') { 
                rightOnes++;
            }
        }

        int max_split_score = leftZeros + rightOnes;
        for (int i = 1;i < s.length() - 1;i++) {
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
```