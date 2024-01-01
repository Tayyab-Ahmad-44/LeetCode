#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int size = arr.size();
        int len = size / 4;

        for (size_t i = 0; i < size - len; i++)
            if (arr[i] == arr[i + len])
                return arr[i];

        return -1;
    }
};

int main()
{
    Solution s;
    // vector<int> arr = {1, 2, 2, 6, 6, 6, 6, 7, 10};
    vector<int> arr = {1, 1};

    cout << s.findSpecialInteger(arr);

    return 0;
}

/*

1287. Element Appearing More Than 25% In Sorted Array

Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.


Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6


Example 2:

Input: arr = [1,1]
Output: 1

*/