# Problem

Alice has `n` balloons arranged on a rope. You are given a 0-indexed string `colors` where `colors[i]` is the color of the `ith` balloon.

Alice wants the rope to be `colorful`. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it `colorful`. You are given a 0-indexed integer array `neededTime` where `neededTime[i]` is the time (in seconds) that Bob needs to remove the `ith` balloon from the rope.

Return the minimum time Bob needs to make the rope `colorful`.

# Approach
The idea is to iterate trough array, and if we find 2 ballons of same color, to check which one is smaller, add that to value and continue.

# Complexity
- Time complexity:
O(n)

- Space complexity:
O(1)

# Code
```cpp
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
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
```