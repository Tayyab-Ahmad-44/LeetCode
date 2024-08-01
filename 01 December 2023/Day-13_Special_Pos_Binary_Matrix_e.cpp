#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int row = mat.size();
        int col = mat[0].size();
        vector<int> rowSum(row, 0);
        vector<int> colSum(col, 0);

        for (size_t i = 0; i < row; i++)
            for (size_t j = 0; j < col; j++)
                if (mat[i][j] == 1)
                {
                    rowSum[i]++;
                    colSum[j]++;
                }

        int ans = 0;

        for (size_t i = 0; i < row; i++)
            for (size_t j = 0; j < col; j++)
                if (mat[i][j] == 1)
                    if (rowSum[i] == 1 && colSum[j] == 1)
                        ans++;
    }
};

int main()
{

    return 0;
}

/*

1582. Special Positions in a Binary Matrix

Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).



Example 1:


Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
Output: 1
Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
Example 2:


Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
Explanation: (0, 0), (1, 1) and (2, 2) are special positions.

*/