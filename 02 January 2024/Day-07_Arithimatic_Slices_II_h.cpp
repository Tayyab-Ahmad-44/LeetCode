#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

using ll = long;
const unsigned int max_n = 1000;
unsigned int dp[max_n][max_n];

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &a)
    {
        unsigned int n = a.size();

        unsigned int res = 0;

        unordered_map<int, vector<unsigned int>> ai = {};

        for (unsigned int i = 0; i < n; i++)
            ai[a[i]].push_back(i);

        for (unsigned int i = 1; i < n; i++)
        {
            for (unsigned int j = 0; j < i; j++)
            {
                dp[i][j] = 0;

                auto p = 2l * a[j] - a[i];

                if (p < INT16_MIN || p > INT16_MAX)
                    continue;

                auto ii = ai.find(p);

                if (ii != ai.end())
                {
                    for (auto k : ai[p])
                    {
                        if (k >= j)
                            break;

                        dp[i][j] += dp[j][k] + 1;
                    }
                }
                res += dp[i][j];
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}

/*

446. Arithmetic Slices II - Subsequence
Hard

Given an integer array nums, return the number of all the arithmetic subsequences of nums.

A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.

For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
The test cases are generated so that the answer fits in 32-bit integer.



Example 1:

Input: nums = [2,4,6,8,10]
Output: 7
Explanation: All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
Example 2:

Input: nums = [7,7,7,7,7]
Output: 16
Explanation: Any subsequence of this array is arithmetic.


*/