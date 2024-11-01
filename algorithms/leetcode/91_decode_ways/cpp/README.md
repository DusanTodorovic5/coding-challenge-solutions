# Problem

A message containing letters from A-Z can be encoded into numbers using the following mapping:

```
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
```
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, `"11106"` can be mapped into:

`"AAJF"` with the grouping `(1 1 10 6)`
`"KJF"` with the grouping `(11 10 6)`
> Note that the grouping `(1 11 06)` is invalid because `"06"` cannot be mapped into `'F'` since `"6"` is different from `"06"`.

Given a string `s` containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a `32-bit` integer.

# Approach

Idea is to count from last element. Next element, if not 0 will have as much ways to do it, and if current can be 2 digit, we add all ways for one before last.

# Complexity
- Time complexity:
O(n)

- Space complexity:
O(1)

# Code
```cpp
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }

        int ways = 0, last = 1, before_last = 0;
        for (int i = s.length() - 1;i >= 0; i--) {
            if (s[i] != '0') {
                ways += last;
            } 
            
            if (i + 1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7'))) {
                ways += before_last;
            }

            before_last = last;
            last = ways;
            ways = 0;
        }

        return last;
    }
};
```