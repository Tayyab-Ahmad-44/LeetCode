#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    //! Brute Force
    /*int maxArea(vector<int> &height)
    {
        int max = min(height[0], height[height.size() - 1]) * (height.size() - 1), area;

        cout << max << " " << height[0] << " " << height[height.size() - 1] << " " << height.size() - 1 << endl;

        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                area = min(height[i], height[j]) * (j - i);

                if (area > max)
                {
                    max = area;
                }
            }
        }
        return max;
    }/**/

    //! Optimum One...
    int maxArea(vector<int> &height)
    {
        int maxArea = -1, area;
        int left = 0, right = height.size() - 1;

        while (left < right)
        {
            area = min(height[left], height[right]) * (right - left);

            cout << height[left] << " " << height[right] << " " << area << " " << right - left << endl;

            maxArea = max(maxArea, area);

            if (height[left] > height[right])
                right--;
            else
                left++;
        }

        return maxArea;
    }
};

int main()
{
    Solution s;

    vector<int> nums = {2, 3, 4, 5, 18, 17, 6};

    cout << s.maxArea(nums);

    return 0;
}

//! 402471897