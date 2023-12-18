# Problem

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

```
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

```
I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.
```

# Approach

This is done in O(n), where n is length of string, because we do not need to check wheter the given string is valid roman number.

Approach is straight forward, go trough each character, if its smaller then next, subtract, otherwise just add it to whole number.

# Code
```cpp
class Solution {
public:
    int romanToInt(string s) {
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
```