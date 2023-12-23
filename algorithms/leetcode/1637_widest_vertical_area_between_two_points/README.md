# Problem

Given `n` `points` on a 2D plane where `points[i] = [xi, yi]`, Return the widest vertical area between two points such that no points are inside the area.

A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.

Note that points on the edge of a vertical area are not considered included in the area.

# Approach
The idea is that if there is a point between 2 other points, those to points cannot be evaluated. In other words, we are looking for maximum difference of two consecutive elements in sorted array.

# Complexity
- Time complexity:
O(nLogn)

- Space complexity:
O(1)

# Code
```cpp
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b){ return a[0] < b[0]; });

        int max = 0;
        for (int i = 0; i < points.size() - 1; i++){
            int width = points[i + 1][0] - points[i][0];
            if (width > max) {
                max = width;
            }
        }

        return max;
    }
};   
```