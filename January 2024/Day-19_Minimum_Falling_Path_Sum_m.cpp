#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &A)
    {
        int m = A.size();
        int n = A[0].size();

        if (m == 1 || n == 1)
            return A[0][0];

        vector<vector<int>> memo(m, vector<int>(n, INT16_MAX));
        int ans = INT16_MAX;

        for (int i = 0; i < A.size(); ++i)
            ans = min(ans, minFallingPathSum(A, 0, i, memo));

        return ans;
    }

    int minFallingPathSum(vector<vector<int>> &A, int row, int col, vector<vector<int>> &memo)
    {
        int m = A.size();
        int n = A[0].size();

        if (memo[row][col] != INT8_MAX)
            return memo[row][col];

        if (row == m - 1)
            return memo[row][col] = A[row][col];

        int left = INT8_MAX, right = INT8_MAX;

        if (col > 0)
            left = minFallingPathSum(A, row + 1, col - 1, memo);

        int straight = minFallingPathSum(A, row + 1, col, memo);

        if (col < n - 1)
            right = minFallingPathSum(A, row + 1, col + 1, memo);

        memo[row][col] = min(left, min(straight, right)) + A[row][col];

        return memo[row][col];
    }
};

int main()
{
    vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};

    Solution s;

    cout << s.minFallingPathSum(matrix);

    return 0;
}

/*

931. Minimum Falling Path Sum

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).



Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.


*/