#include <iostream>
#include <vector>
#include <stack>

using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

class Solution
{
public:
    int sumSubarrayMins(vector<int> &nums)
    {
        int length = nums.size();
        vector<int> left(length, -1);
        vector<int> right(length, length);
        stack<int> stk;

        for (int i = 0; i < length; ++i)
        {
            while (!stk.empty() && nums[stk.top()] >= nums[i])
            {
                stk.pop();
            }
            if (!stk.empty())
            {
                left[i] = stk.top();
            }
            stk.push(i);
        }

        stk = stack<int>();

        for (int i = length - 1; i >= 0; --i)
        {
            while (!stk.empty() && nums[stk.top()] > nums[i])
            {
                stk.pop();
            }
            if (!stk.empty())
            {
                right[i] = stk.top();
            }
            stk.push(i);
        }

        ll sum = 0;

        for (int i = 0; i < length; ++i)
        {
            sum += static_cast<ll>(i - left[i]) * (right[i] - i) * nums[i] % MOD;
            sum %= MOD;
        }

        return sum;
    }
};

/*

907. Sum of Subarray Minimums
Solved
Medium
Topics
Companies
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.


Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:

Input: arr = [11,81,94,43,3]
Output: 444

*/