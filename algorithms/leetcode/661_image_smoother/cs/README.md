# Problem

An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).

![https://assets.leetcode.com/uploads/2021/05/03/smoother-grid.jpg](https://assets.leetcode.com/uploads/2021/05/03/smoother-grid.jpg)

Given an m x n integer matrix img representing the grayscale of an image, return the image after applying the smoother on each cell of it.

# Approach
We calculate average for each cell by iterating around it.

# Complexity
- Time complexity:
O(n^2)

- Space complexity:
O(n^2)

# Code
```cs
public class Solution {
    public int[][] ImageSmoother(int[][] img)
    {
        if (img.Length == 0)
        {
            return img;
        }

        int[][] new_img = new int[img.Length][];
        for (int i = 0; i < img.Length; i++)
        {
            new_img[i] = new int[img[i].Length];
            for (int j = 0; j < img[i].Length; j++)
            {
                new_img[i][j] = CalculateAverage(ref img, i, j);
            }
        }

        return new_img;
    }

    public int CalculateAverage(ref int[][] img, int rowIndex, int colIndex)
    {
        int sum = 0;
        int count = 0;

        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if (rowIndex + i < 0 || rowIndex + i >= img.Length || colIndex + j < 0 || colIndex + j >= img[rowIndex].Length)
                {
                    continue;
                }

                sum += img[rowIndex + i][colIndex + j];
                count++;
            }
        }
    
        return sum / count;
    }
}
```