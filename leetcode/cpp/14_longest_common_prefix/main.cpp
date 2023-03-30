#include <iostream>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
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

int main() {
    Solution sol;

    std::vector<std::vector<std::string>> strs_arr = {
        {"dog", "doggy", "doghouse", "dogg"},
        {"house", "housing", "hhouus"},
        {"longest", "long", "short"},
        {"abcc", "abccc", "abcccc"},
        {"this is very long string", "this is very very long string", "this is very long string with mulptile stuff", "this is very wow long string wow"},
        {"more long string", "more long strings comming this way", "more long strings are comming!!!"}
    };

    for (int i=0;i<strs_arr.size();i++) {
        std::cout << sol.longestCommonPrefix(strs_arr[i]) << std::endl;
    }
    return 0;
}