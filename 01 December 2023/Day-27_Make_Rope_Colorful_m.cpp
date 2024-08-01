#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        //! These Damn Statements make your program runs faster AF...!
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int res = 0;

        //! Naive -> TLE
        /*
            for (size_t i = 1; i < colors.length(); i++)
            if (colors[i] == colors[i - 1])
            {
                int indexToRemove = (neededTime[i] < neededTime[i - 1]) ? i : i - 1;
                colors.erase(i, 1);
                res += neededTime[indexToRemove];
                neededTime.erase(neededTime.begin() + indexToRemove);
                i--;
            }
        /**/

        //! Good
        for (size_t i = 1; i < colors.length(); i++)
            if (colors[i] == colors[i - 1])
            {
                int indexToRemove = (neededTime[i] < neededTime[i - 1]) ? i : i - 1;
                int indexToKeep = (neededTime[i] < neededTime[i - 1]) ? i - 1 : i;

                res += neededTime[indexToRemove];
                neededTime[i] = neededTime[indexToKeep];
            }

        return res;
    }
};

int main()
{
    // string colors = "abaac";
    // vector<int> neededTime = {1, 2, 3, 4, 5};

    // string colors = "abc";
    // vector<int> neededTime = {1, 2, 3};

    string colors = "aabaa";
    vector<int> neededTime = {1, 2, 3, 4, 1};

    Solution s;

    cout << s.minCost(colors, neededTime);

    return 0;
}

/*

1578. Minimum Time to Make Rope Colorful

Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.



Example 1:


Input: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3
Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
Bob can remove the blue balloon at index 2. This takes 3 seconds.
There are no longer two consecutive balloons of the same color. Total time = 3.
Example 2:


Input: colors = "abc", neededTime = [1,2,3]
Output: 0
Explanation: The rope is already colorful. Bob does not need to remove any balloons from the rope.
Example 3:


Input: colors = "aabaa", neededTime = [1,2,3,4,1]
Output: 2
Explanation: Bob will remove the ballons at indices 0 and 4. Each ballon takes 1 second to remove.
There are no longer two consecutive balloons of the same color. Total time = 1 + 1 = 2.

*/