#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int len = jobDifficulty.size();

        if (len < d)
        {
            return -1;
        }

        int sum = accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0);

        if (sum == 0)
        {
            return 0;
        }

        vector<vector<int>> memo(d + 1, vector<int>(len, 0));

        helper(jobDifficulty, d, 0, memo);

        return memo[d][0];
    }

private:
    void helper(vector<int> &jd, int daysLeft, int idx, vector<vector<int>> &memo)
    {
        int len = jd.size();
        if (memo[daysLeft][idx] != 0)
        {
            return;
        }
        if (daysLeft == 1)
        {
            int num = 0;
            for (int i = idx; i < len; i++)
            {
                num = max(num, jd[i]);
            }
            memo[daysLeft][idx] = num;
            return;
        }
        int maxDifficulty = jd[idx];
        daysLeft--;
        int stop = len - idx - daysLeft + 1;

        int res = INT16_MAX;
        for (int i = 1; i < stop; i++)
        {
            maxDifficulty = max(maxDifficulty, jd[idx + i - 1]);
            int other = memo[daysLeft][idx + i];
            if (other == 0)
            {
                helper(jd, daysLeft, idx + i, memo);
                other = memo[daysLeft][idx + i];
            }
            res = min(res, other + maxDifficulty);
        }
        memo[daysLeft + 1][idx] = res;
    }
};

/*

1335. Minimum Difficulty of a Job Schedule
Hard

You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done on that day.

You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].

Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.



Example 1:


Input: jobDifficulty = [6,5,4,3,2,1], d = 2
Output: 7
Explanation: First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7
Example 2:

Input: jobDifficulty = [9,9,9], d = 4
Output: -1
Explanation: If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.
Example 3:

Input: jobDifficulty = [1,1,1], d = 3
Output: 3
Explanation: The schedule is one job per day. total difficulty will be 3.

*/