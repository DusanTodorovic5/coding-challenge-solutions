#include <iostream>

// Convert roman number to decimal number

class Solution {
public:
    int romanToInt(std::string s) {
        int decimal = 0;
        // going trough each character
        for (int i=0;i<s.length();i++) {
            // convert the character to number
            int decimal_digit = baseRomanToInt(s[i]);
            // if the decimal number is smaller then next, subtract it
            if (i < s.length() - 1 && decimal_digit < baseRomanToInt(s[i + 1])) {
                decimal -= decimal_digit;
            } else {
                // add the character to number
                decimal += decimal_digit;
            }
        }
        // return the number
        return decimal;
    }
    // utility function to convert character to int value
    inline int baseRomanToInt(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
};

int main(int, char**) {
    
}
