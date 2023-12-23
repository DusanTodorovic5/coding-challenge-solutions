# Problem

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

# Approach
We do not need to compare all of the strings, instead, we only need to compare longest and shortest string.
Shortest string is longest possible prefix.

The reason we do not need to compare rest is because, if 2 strings have different prefix, they will be found as longest and shortest, therefore the algorithm will return "".

# Complexity
Time complexity of this algorithm is O(N + M), where N is the length of array and M is length of the shortest string.

# Code
```
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // check if array is empty
        if (strs.empty()) {
            return "";
        }

        int shortest = 0;
        int longest = 0;

        // find shortest and longest string for compare
        for (int i=0;i<strs.size();i++) {
            if (strs[i] < strs[shortest]) {
                shortest = i;
                continue;
            }

            if (strs[i] > strs[longest]) {
                longest = i;
            }
        }

        // check if shortest is really shortest, if not, swap them
        // why? z > aaaa, so aaaa will be in shortest and z in longest 
        if (strs[shortest].length() > strs[longest].length()) {
            std::swap(shortest, longest);
        }

        // iterate trough character in shortest string
        for (int index = 0;index < strs[shortest].length(); ++index) {
            // if characters do not match, the longest substring was found
            if (strs[longest][index] != strs[shortest][index]) {
                return strs[shortest].substr(0, index);
            }
        }

        // return shortest string, as it is longest substring
        return strs[shortest];
    }
};
```