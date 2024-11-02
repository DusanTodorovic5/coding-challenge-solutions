# 7. Reverse Integer

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

# Solution

```cpp
class Solution {
public:
    int reverse(int x) {
        const int max_int = std::pow(2, 31) - 1;
        const int min_int = std::pow(2, 31) * -1;
        bool sign = x < 0;
        int new_number = 0;
        x = std::abs(x);

        while (x) {
            if (new_number >=  max_int / 10 + x % 10 || new_number <= min_int/ 10 - x % 10) {
                return 0;
            }

            new_number *= 10;
            new_number += x % 10;
            x /= 10;
        }

        return new_number * (sign ? - 1 : 1);
    }
};
```
