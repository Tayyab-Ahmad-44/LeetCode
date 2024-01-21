#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int rob = 0;
        int norob = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int newRob = norob + nums[i];
            int newNoRob = max(norob, rob);
            rob = newRob;
            norob = newNoRob;
        }
        return max(rob, norob);
    }
};

/*

198. House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.


Example 3:
Input: [2, 1, 1, 2]
Output: 4

*/

/*
!Dry Run
Input: 2, 1, 1, 2
rob = 0, norob = 0

newRob = norob + nums[0] = 0 + 2 = 2
newNoRob = max(0, 0) = 0
rob = 2
norob = 0

newRob = 0 + 1 = 1
newNoRob = 2, 1 = 2
rob = 1
norob = 2

newRob = 2 + 1 = 3
newNoRob = 1, 2 = 2
rob = 3
noRob = 2

newRob = 2 + 2 = 4
newNoRob = 2, 3
rob = 4
newNoRob = 3

*/