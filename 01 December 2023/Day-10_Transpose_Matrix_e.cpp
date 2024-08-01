#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> resMatrix(col, vector<int>(rows));

        for (size_t i = 0; i < rows; i++)
            for (size_t j = 0; j < col; j++)
                resMatrix[j][i] = matrix[i][j];

        return resMatrix;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> matrix = {{1, 2, 3, 4}, {4, 5, 6, 7}, {7, 8, 9, 10}};

    vector<vector<int>> matrixx = s.transpose(matrix);

    for (size_t i = 0; i < matrixx.size(); i++)
    {
        for (size_t j = 0; j < matrixx[0].size(); j++)
            cout << matrixx[i][j] << " ";

        cout << endl;
    }

    return 0;
}

//! Transpose of a matrix