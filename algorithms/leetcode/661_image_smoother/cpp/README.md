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
```cpp
class Solution {
public:
    std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& img) {
        if (!img.size()) {
            return img;
        }

        std::vector<std::vector<int>> new_img(img.size(), std::vector<int>(img[0].size(), 0));

        for (int i = 0; i < img.size(); i++) {
            for (int j = 0; j < img[i].size(); j++) {
                new_img[i][j] = calculateAverage(img, i, j);
            }
        }

        return new_img;
    }
private:
    int calculateAverage(const std::vector<std::vector<int>>& img, int row_index, int col_index) {
        int sum = 0;
        int count = 0;

        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                int row = row_index + i;
                int col = col_index + j;

                if (row > -1 && row < img.size() && col > -1 && col < img[row_index].size()) {
                    sum += img[row][col];
                    ++count;
                }
            }
        }

        return sum / count;
    }
};
```