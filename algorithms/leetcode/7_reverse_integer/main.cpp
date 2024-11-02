#include <iostream>

int reverse(int x)
{
    const int max_int = std::pow(2, 31) - 1;
    const int min_int = std::pow(2, 31) * -1;
    bool sign = x < 0;
    int new_number = 0;
    x = std::abs(x);

    while (x)
    {
        if (new_number > max_int - x % 10 || new_number < min_int + x % 10)
        {
            return 0;
        }

        new_number *= 10;
        new_number += x % 10;
        x %= 10;
    }

    return new_number;
}

int main()
{
    return reverse(333333333);
}