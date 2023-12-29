#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation

class MountainArray
{
public:
    int get(int index);
    int length();
};

class Solution
{
public:
    int maximum(MountainArray &mountainArr)
    {
        int mid_val, mid_left, mid_right;
        int left = 0, right = mountainArr.length() - 1, mid;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            mid_val = mountainArr.get(mid);

            mid_left = mountainArr.get(mid - 1);
            mid_right = mountainArr.get(mid + 1);

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
    };

    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int max = maximum(mountainArr);
        if (mountainArr.get(max) == target)
            return max;
        int left = 0, right = max, mid, mid_val;

        while (left < right)
        {
            mid = left + (right - left) / 2;
            mid_val = mountainArr.get(mid);

            if (mid_val == target)
                return mid;
            if (mid_val > target)
                right = mid;
            else
                left = mid + 1;
        }

        left = max + 1, right = mountainArr.length() - 1;

        while (left < right)
        {
            mid = left + (right - left) / 2;
            mid_val = mountainArr.get(mid);

            if (mid_val == target)
                return mid;
            else if (mid_val > target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        if (left == right && mountainArr.get(left) == target)
            return left;

        return -1;
    }
};