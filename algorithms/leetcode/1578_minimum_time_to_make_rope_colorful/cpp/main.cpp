#include <iostream>
#include <vector>

class Solution {
public:
    int minCost(std::string colors, std::vector<int>& neededTime) {
        int time = 0;

        int currentMinimalTime = neededTime[0];
        char currentCharacter = colors[0];
        for (int i = 1; i < colors.length(); i++) {
            if (currentCharacter == colors[i]) {
                if (currentMinimalTime < neededTime[i]) {
                    time += std::exchange(currentMinimalTime, neededTime[i]);
                }
                else {
                    time += neededTime[i];
                }
            }
            else {
                currentCharacter = colors[i];
                currentMinimalTime = neededTime[i];
            }
        }

        return time;
    }
};

int main(int, char**){
    std::cout << "Hello, from colorful_rope!\n";
}
