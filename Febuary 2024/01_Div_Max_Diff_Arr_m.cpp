#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int> &nums, int k)
    {
        int div = nums.size() / 3;
        int size = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans(div, vector<int>(3, 0));

        ans[0][0] = nums[0];

        int row = 0;
        int col = 1;

        for (int i = 1; i < size; i++)
        {
            if (i % 3 == 0 && i != size - 1)
            {
                row++;
                col = 1;
                ans[row][0] = nums[i];
                i++;
            }

            // cout << "hi" << i;
            if (nums[i] - ans[row][0] <= k)
                ans[row][col++] = nums[i];
            else
                return {};
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 3, 3, 2, 7, 3};
    // vector<int> nums = {1, 3, 4, 8, 7, 9, 3, 5, 1};

    Solution s;

    vector<vector<int>> ans = s.divideArray(nums, 2);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ans[i][j] << endl;
        }
    }

    return 0;
}