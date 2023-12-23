#include <iostream>
/*
Given an integer x, return true if x is a palindrome, and false otherwise.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        // Numbers that are negative are not palindrome by default
        // Also we can return false for all numbers ending in 0
        if (x < 0 || (x % 10 == 0 && x > 9)) {
            return false;
        }

        // we create a variable to store reverse number in
        unsigned int x_rev = x % 10;
        // For each digit in x, add it to x_rev
        for (int tmp = x / 10; tmp != 0 ;tmp /= 10){
            x_rev = x_rev * 10 + tmp % 10;
        }

        // Return whether x is equal to x_rev
        return x == x_rev;
    }
};


int main(int, char**) {
    return 0;
}

