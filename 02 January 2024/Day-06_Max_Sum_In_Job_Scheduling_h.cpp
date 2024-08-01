#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// class Solution
// {
// public:
//     int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
//     {
//         ios::sync_with_stdio(0);
//         cin.tie(0);
//         cout.tie(0);

//         int numJobs = profit.size(); // Number of jobs
//         vector<tuple<int, int, int>> jobs(numJobs);

//         for (int i = 0; i < numJobs; ++i)
//         {
//             jobs[i] = {endTime[i], startTime[i], profit[i]};
//         }

//         sort(jobs.begin(), jobs.end());
//         vector<int> dp(numJobs + 1);

//         for (int i = 0; i < numJobs; ++i)
//         {
//             auto [endTime, startTime, profit] = jobs[i];

//             int latestNonConflictJobIndex = upper_bound(jobs.begin(), jobs.begin() + i, startTime, [&](int time, const auto &job) -> bool
//                                                         { return time < get<0>(job); }) -
//                                             jobs.begin();

//             dp[i + 1] = max(dp[i], dp[latestNonConflictJobIndex] + profit);
//         }

//         return dp[numJobs];
//     }
// };

int main()
{

    return 0;
}

/*

1235. Maximum Profit in Job Scheduling
Hard

We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.



Example 1:



Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job.
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
Example 2:



Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job.
Profit obtained 150 = 20 + 70 + 60.
Example 3:



Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6

*/