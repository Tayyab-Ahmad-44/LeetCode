#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        int rows = grid.size(), col = grid[0].size();

        vector<int> onesRow(rows, 0);
        vector<int> onesCol(col, 0);

        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                onesRow[i] += grid[i][j];
                onesCol[j] += grid[i][j];
            }
        }

        vector<vector<int>> res(rows, vector<int>(col, 0));

        //  diff[i][j] = onesRow[i] + onesCol[j] - (N - onesRow[i]) - (M - onesCol[j])
        //     = 2 * onesRow[i] + 2 * onesCol[j] - N - M

        for (size_t i = 0; i < rows; i++)
            for (size_t j = 0; j < col; j++)
                res[i][j] = 2 * onesRow[i] + 2 * onesCol[j] - rows - col;

        return res;
    }
};

int main()
{
    // vector<vector<int>> grid = {{0, 1, 1}, {1, 0, 1}, {0, 0, 1}};
    vector<vector<int>> grid = {{1, 1, 1}, {1, 1, 1}};

    Solution s;

    vector<vector<int>> res = s.onesMinusZeros(grid);

    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < grid[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*

2482. Difference Between Ones and Zeros in Row and Column
Medium

You are given a 0-indexed m x n binary matrix grid.

A 0-indexed m x n difference matrix diff is created with the following procedure:

Let the number of ones in the ith row be onesRowi.
Let the number of ones in the jth column be onesColj.
Let the number of zeros in the ith row be zerosRowi.
Let the number of zeros in the jth column be zerosColj.
diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
Return the difference matrix diff.



Example 1:


Input: grid = [[0,1,1],[1,0,1],[0,0,1]]
Output: [[0,0,4],[0,0,4],[-2,-2,2]]
Explanation:
- diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 2 + 1 - 1 - 2 = 0
- diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 2 + 1 - 1 - 2 = 0
- diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 2 + 3 - 1 - 0 = 4
- diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 2 + 1 - 1 - 2 = 0
- diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 2 + 1 - 1 - 2 = 0
- diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 2 + 3 - 1 - 0 = 4
- diff[2][0] = onesRow2 + onesCol0 - zerosRow2 - zerosCol0 = 1 + 1 - 2 - 2 = -2
- diff[2][1] = onesRow2 + onesCol1 - zerosRow2 - zerosCol1 = 1 + 1 - 2 - 2 = -2
- diff[2][2] = onesRow2 + onesCol2 - zerosRow2 - zerosCol2 = 1 + 3 - 2 - 0 = 2
Example 2:


Input: grid = [[1,1,1],[1,1,1]]
Output: [[5,5,5],[5,5,5]]
Explanation:
- diff[0][0] = onesRow0 + onesCol0 - zerosRow0 - zerosCol0 = 3 + 2 - 0 - 0 = 5
- diff[0][1] = onesRow0 + onesCol1 - zerosRow0 - zerosCol1 = 3 + 2 - 0 - 0 = 5
- diff[0][2] = onesRow0 + onesCol2 - zerosRow0 - zerosCol2 = 3 + 2 - 0 - 0 = 5
- diff[1][0] = onesRow1 + onesCol0 - zerosRow1 - zerosCol0 = 3 + 2 - 0 - 0 = 5
- diff[1][1] = onesRow1 + onesCol1 - zerosRow1 - zerosCol1 = 3 + 2 - 0 - 0 = 5
- diff[1][2] = onesRow1 + onesCol2 - zerosRow1 - zerosCol2 = 3 + 2 - 0 - 0 = 5


*/