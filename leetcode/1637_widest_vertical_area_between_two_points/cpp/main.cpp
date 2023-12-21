#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) {
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

int main(int, char**){
    std::cout << "Hello, from widest_vertical_area!\n";
}
