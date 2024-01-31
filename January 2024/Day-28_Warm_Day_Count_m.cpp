#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> result(temperatures.size(), 0);
        vector<int> stack;

        for (int i = temperatures.size() - 1; i >= 0; --i)
        {
            int currTemperature = temperatures[i];

            while (!stack.empty() && currTemperature >= temperatures[stack.back()])
            {
                stack.pop_back();
            }

            if (!stack.empty())
            {
                result[i] = stack.back() - i;
            }

            stack.push_back(i);
        }

        return result;
    }
};

int main()
{

    return 0;
}

/*

739. Daily Temperatures

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.



Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]

*/