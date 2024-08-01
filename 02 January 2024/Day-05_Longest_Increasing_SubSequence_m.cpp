#include <iostream>
#include <vector>

using namespace std;

//! Approach is mentioned below...
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> tails(nums.size(), 0);

        int size = 0;

        for (int x : nums)
        {
            int i = 0, j = size;
            while (i != j)
            {
                int m = (i + j) / 2;
                if (tails[m] < x)
                    i = m + 1;
                else
                    j = m;
            }

            tails[i] = x;

            if (i == size)
                ++size;
        }
        return size;
    }
};

// class Solution
// {
// public:
//     int lengthOfLIS(std::vector<int> &nums)
//     {
//         if (nums.empty())
//         {
//             return 0;
//         }

//         int n = nums.size();
//         std::vector<int> dp(n, 1);

//         for (int i = 1; i < n; ++i)
//         {
//             for (int j = 0; j < i; ++j)
//             {
//                 if (nums[i] > nums[j])
//                 {
//                     dp[i] = std::max(dp[i], dp[j] + 1);
//                 }
//             }
//         }

//         return *std::max_element(dp.begin(), dp.end());
//     }
// };

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    Solution s;

    s.lengthOfLIS(nums);

    return 0;
}

/*

300. Longest Increasing Subsequence
Medium

!Given an integer array nums, return the length of the longest strictly increasing subsequence

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1

*/

// Todo ------------------------------------------------------------------------------------------------------------------

/*

! Approach
We can solve this problem efficiently using dynamic programming. The key idea is to maintain an array tails where tails[i]
represents the smallest ending element of all increasing subsequences of length i+1. This array is crucial in determining
where the current element x fits in the existing subsequences.

    ? Initialize an array tails of the same length as nums to store the ending elements of increasing subsequences.

    ? Initialize a variable size to keep track of the current length of the longest increasing subsequence.

    ? Iterate through each element x in nums:

* Use binary search to find the correct position for x in the tails array.

* Update the corresponding position in tails with x.

* If x is greater than all ending elements in tails, append it to the end and increment size.

* The final value of size represents the length of the longest increasing subsequence.

*/