#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int mid_val, mid_left, mid_right;
        int left = 0, right = arr.size() - 1, mid;

        while (left < right)
        {
            mid = left + (right - left) / 2;
            mid_val = arr[mid];

            mid_left = arr[mid - 1];
            mid_right = arr[mid + 1];

            if (mid_val > mid_left && mid_val > mid_right)
            {
                return mid;
            }
            if (mid_val > mid_left)
            {
                left = mid;
            }
            else if (mid_val > mid_right)
            {
                right = mid;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {0, 5, 3, 1};

    cout << s.peakIndexInMountainArray(arr);
}