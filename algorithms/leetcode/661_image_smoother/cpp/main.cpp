#include <iostream>
#include <vector>

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

int main(int, char**){
    std::cout << "Hello, from image_smoother!\n";
}
