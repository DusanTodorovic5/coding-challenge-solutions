#include <iostream>
#include <vector>

class Solution {
public:
    int numDecodings(std::string s) {
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

int main(int, char**){
    std::cout << (Solution().numDecodings("12"));
}
