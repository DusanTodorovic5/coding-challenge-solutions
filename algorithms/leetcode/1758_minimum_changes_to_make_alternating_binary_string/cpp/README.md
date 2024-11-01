# Problem

You are given a string s consisting only of the characters `'0'` and `'1'`. In one operation, you can change any `'0'` to `'1'` or vice versa.

The string is called alternating if no two adjacent characters are equal. For example, the string `"010"` is alternating, while the string `"0100"` is not.

Return the minimum number of operations needed to make s alternating.

# Approach
We count how many `'1'` are on even and how many `'0'` are on odd places. That would be the number of changes required for chaning if string started with `'0'`. If the string starts with `'1'`, we need reversed from that, which is in fact `length - count`.

# Complexity
- Time complexity:
O(n)

- Space complexity:
O(1)

# Code
```cpp
class Solution {
public:
    int minOperations(string s) {
        if (s.length() < 2) {
            return 0;
        }
        
        int count = 0;
        char comparables[2]{'1', '0'};
        for (int i = 0; i < s.length(); i++) {
          if (s[i] == comparables[i%2]) {
            count++;
          }
        }

        return std::min(count, (int)s.length() - count);
    }
};
```