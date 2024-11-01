#include <iostream>

class Solution {
public:
    std::string makeFancyString(std::string s) {
        std::string new_string = "";

        int consecutive = 0;
        for (auto& c : s) {
            if (new_string.length() && new_string[new_string.length() - 1] == c) {
                consecutive++;
            } else {
                consecutive = 1;
            }

            if (consecutive < 3) {
                new_string += c;
            }
        }

        return new_string;
    }
};