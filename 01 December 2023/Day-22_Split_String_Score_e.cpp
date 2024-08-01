#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxScore(string s)
    {
        int oneCount = 0;
        int len = s.length();

        for (size_t i = 0; i < len; i++)
            if (s[i] == '1')
                oneCount++;

        int res = -1;
        for (size_t i = 1; i < len; i++)
        {
            string left = s.substr(0, i);

            int ones = oneCount;
            int zeros = 0;

            for (size_t j = 0; j < left.length(); j++)
                if (left[j] == '0')
                    zeros++;
                else
                    ones--;
            res = max(res, zeros + ones);
        }
        return res;
    }
};

int main()
{
    Solution s;

    s.maxScore("011101");

    return 0;
}