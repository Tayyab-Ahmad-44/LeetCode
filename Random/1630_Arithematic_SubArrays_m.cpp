#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        vector<bool> results(l.size());
        vector<int> num;
        bool yes = true;

        if (l.size() == r.size())
            for (size_t i = 0; i < l.size(); i++)
            {
                vector<int> num(nums.begin() + l[i], nums.begin() + r[i] + 1);

                sort(num.begin(), num.end());

                for (int j = 2; j < num.size(); j++)
                {
                    if (num[j] - num[j - 1] != num[1] - num[0])
                    {
                        results[i] = false;
                        yes = false;
                        break;
                    }
                }
                if (yes)
                    results[i] = true;

                yes = true;
            }
        else
            return results;
    }
};

int main()
{
    vector<int> nums = {4, 6, 5, 9, 3, 7}, l = {0, 0, 2}, r = {2, 3, 5};

    Solution s;

    vector<bool> result = s.checkArithmeticSubarrays(nums, l, r);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}
