#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        vector<int> xs;
        for (auto &p : points)
            xs.push_back(p[0]);

        sort(xs.begin(), xs.end());

        int M = INT16_MIN;
        for (int i = 1; i < xs.size(); i++)
            M = max(M, xs[i] - xs[i - 1]);

        return M;
    }
};

int main()
{
    vector<vector<int>> points = {{8, 7}, {9, 9}, {7, 4}, {9, 7}};

    Solution s;

    cout << s.maxWidthOfVerticalArea(points);

    return 0;
}

/*

1637. Widest Vertical Area Between Two Points Containing No Points

Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.

A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.

Note that points on the edge of a vertical area are not considered included in the area.



Example 1:

​
Input: points = [[8,7],[9,9],[7,4],[9,7]]
Output: 1
Explanation: Both the red and the blue area are optimal.
Example 2:

Input: points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
Output: 3

*/