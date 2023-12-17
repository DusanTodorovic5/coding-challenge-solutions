/*
 * There is a robot on an m x n grid. The robot is initially located at the top-left corner 
 * (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
 * The robot can only move either down or right at any point in time.
 * Given the two integers m and n, return the number of possible unique 
 * paths that the robot can take to reach the bottom-right corner.
 * The test cases are generated so that the answer will be less than or equal to 2 * 109.
*/
public class Solution {
    public int UniquePaths(int m, int n) {
        if (m < 2 || n < 2)
        {
            return 1;
        }

        // Initialize the gridRow with all 1
        // This is our first row of matrix
        int[] gridRow = new int[n];
        for (int i = 0;i<n; gridRow[i++] = 1);

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

    public static void Main(string[] args)
    {
        Solution solution = new();

        Console.WriteLine(solution.UniquePaths(3, 7));
    }
}