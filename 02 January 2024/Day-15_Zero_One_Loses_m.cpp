#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int size = matches.size();
        vector<int> not_lost;
        vector<int> one_lost;
        unordered_map<int, int> freq_lost;
        unordered_set<int> nums;

        for (int i = 0; i < size; i++)
        {
            nums.insert(matches[i][0]);
            nums.insert(matches[i][1]);
            freq_lost[matches[i][1]]++;
        }

        for (auto it : freq_lost)
            if (it.second == 1)
                one_lost.push_back(it.first);

        for (auto it : nums)
            if (freq_lost.find(it) == freq_lost.end())
                not_lost.push_back(it);

        sort(not_lost.begin(), not_lost.end());
        sort(one_lost.begin(), one_lost.end());

        vector<vector<int>> ans;

        ans.push_back(not_lost); // 1, 2, 10
        ans.push_back(one_lost); // 4, 5, 7, 8

        return ans;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> matches = {{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};

    s.findWinners(matches);

    return 0;
}

/*

2225. Find Players With Zero or One Losses

You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:

answer[0] is a list of all players that have not lost any matches.
answer[1] is a list of all players that have lost exactly one match.
The values in the two lists should be returned in increasing order.

Note:

You should only consider the players that have played at least one match.
The testcases will be generated such that no two matches will have the same outcome.


Example 1:

Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
Output: [[1,2,10],[4,5,7,8]]
Explanation:
Players 1, 2, and 10 have not lost any matches.
Players 4, 5, 7, and 8 each have lost one match.
Players 3, 6, and 9 each have lost two matches.
Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].
Example 2:

Input: matches = [[2,3],[1,3],[5,4],[6,4]]
Output: [[1,2,5,6],[]]
Explanation:
Players 1, 2, 5, and 6 have not lost any matches.
Players 3 and 4 each have lost two matches.
Thus, answer[0] = [1,2,5,6] and answer[1] = [].

*/