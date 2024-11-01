#include <iostream>
#include <cmath>

class Solution {
public:
    int minOperations(std::string s) {
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

int main(int, char**){
    std::cout << Solution().minOperations("10010100") << std::endl;

    return 0;
}
