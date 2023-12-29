#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int count = 0;

        for (size_t i = 0; i < points.size() - 1; i++)
        {
            int diff_X = points[i][0] - points[i + 1][0];
            int diff_Y = points[i][1] - points[i + 1][1];

            int maxi = max(abs(diff_X), abs(diff_Y));

            count += maxi;
        }

        return count;
    }
};

int main()
{
    Solution s;
    // vector<vector<int>> points = {{1, 1}, {3, 4}, {-1, 0}};
    vector<vector<int>> points = {{3, 2}, {-2, 2}};

    cout << s.minTimeToVisitAllPoints(points);

    return 0;
}