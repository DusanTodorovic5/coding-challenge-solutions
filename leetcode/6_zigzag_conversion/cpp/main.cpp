/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);


NOT OPTIMIZED
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    std::string convert(std::string s, int numRows)
    {
        // If its less then 2 rows, we return unchanged string
        if (numRows < 2)
        {
            return s;
        }

        // Allocate string and matrix for railfence
        std::string result(s.length(), '\0');
        std::vector<std::vector<char>> matrix(numRows, std::vector<char>(s.length(), '\0'));

        // Fill in the holder with *, this is where we will set characters
        bool direction = true;
        for (int i = 0, row = 0, col = 0; i < s.length(); i++)
        {
            matrix[row][col] = '*';

            if ((row == numRows - 1 && direction) || (row == 0 && !direction))
            {
                direction = !direction;
            }

            if (direction)
            {
                ++row;
            }
            else
            {
                --row;
                ++col;
            }
        }

        // Set characters traversing columns first
        for (int j = 0, k = 0; j < s.length(); j++)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                if (matrix[i][j] != '\0')
                {
                    matrix[i][j] = s[k++];
                }
            }
        }

        // Populate string by pulling characters from matrix rows first
        for (int i = 0, k = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < s.length(); j++)
            {
                if (matrix[i][j] != '\0')
                {
                    result[k++] = matrix[i][j];
                }
            }
        }

        return result;
    }
};

int main(int, char **)
{
    Solution sol;

    std::cout << sol.convert("PAYPALISHIRING", 3) << std::endl;
}
