#include <iostream>
#include <vector>

class Solution {
public:
    int buyChoco(std::vector<int>& prices, int money) {
        if (prices.size() < 2) {
            return money;
        }

        int min1 = money, min2 = money;
        for (int price : prices) {
            if (price < min1) {
                min2 = min1;
                min1 = price;
            } else if (price < min2) {
                min2 = price;
            }
        }

        int leftover = money - (min1 + min2);
        return leftover >= 0 ? leftover : money;
    }
};

int main(int, char**){
    std::cout << "Hello, from buy_two_chocolates!\n";
}
