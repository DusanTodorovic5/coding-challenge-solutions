# Idea
The idea is to reverse the number and check if its equal

# Complexity
Time complexity is O(n), where n is the number of digits. The complexity can be O(n/2) using std::to_string to convert it, but remember that conversion also takes some time, and at the end, it will actually be a slower solution.
In the test I put together, it was 6-7 times faster to use integers instead of converting it to string.

# Code
```cpp
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
```

# Results

100% runtime efficiency.