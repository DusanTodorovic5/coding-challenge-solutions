# Approach
The idea is to simple. As we can move only right and down, we can calculate the number of paths for that field as sum of number of paths for field left and up. The first column and row always have only 1 path. 
The optimization that is done here, to make things a bit faster and to save on memory, is to memorize only 1 row. This way, we calculate new value as current + left field.

# Complexity
- Time complexity:
O(n*m)

- Space complexity:
O(n)

# Code
```cs
public class Solution {
    public int UniquePaths(int m, int n) {
        if (m < 2 || n < 2)
        {
            return 1;
        }

        // Initialize the gridRow with all 1
        // This is our first row of matrix
        int[] gridRow = new int[n];
        for (int i = 0;i < n; gridRow[i++] = 1);
        

        // No need to memorize each row, only the current one
        // because the sum is current + left, where row[0] is always 1
        while (m-- > 1)
        {
            for (int i = 1; i < n; i++)
            {
                gridRow[i] += gridRow[i - 1];
            }
        }

        // We return last element in array, that is actually our value
        return gridRow[n - 1];
    }
}
```