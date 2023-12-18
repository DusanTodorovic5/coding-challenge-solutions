# Problem

The product difference between two pairs `(a, b)` and `(c, d)` is defined as `(a * b) - (c * d)`.

For example, the product difference between `(5, 6)` and (2, 7) is `(5 * 6) - (2 * 7) = 16`.
Given an integer array nums, choose four distinct indices `w`, `x`, `y`, and `z` such that the product difference between pairs `(nums[w], nums[x])` and `(nums[y], nums[z])` is maximized.

Return the maximum such product difference.

# Approach
The idea is to find 2 maximum and 2 minimal values. First product is 2 maximum, second is 2 minimum. The difference will be maximum value in given array.

# Complexity
- Time complexity:
O(n)

- Space complexity:
O(1)

# Code
```cs
public class Solution {
    public int MaxProductDifference(int[] nums) {
        if (nums.Length < 4)
        {
            return 0;
        }

        int[] chosenPairs = {int.MinValue, int.MinValue, int.MaxValue, int.MaxValue};

        foreach (int num in nums)
        {
            if (num < chosenPairs[2])
            {
                chosenPairs[3] = chosenPairs[2];
                chosenPairs[2] = num;
            } 
            else if (num < chosenPairs[3])
            {
                chosenPairs[3] = num;
            }
            
            if (num > chosenPairs[0])
            {
                chosenPairs[1] = chosenPairs[0];
                chosenPairs[0] = num;
            }
            else if (num > chosenPairs[1])
            {
                chosenPairs[1] = num;
            }
        }

        return (chosenPairs[0]  * chosenPairs[1]) - (chosenPairs[2] * chosenPairs[3]);
    }
}
```