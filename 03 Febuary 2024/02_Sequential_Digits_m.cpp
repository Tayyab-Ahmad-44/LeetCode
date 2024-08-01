#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        string loww = to_string(low);
        string start;

        start.push_back(loww[0]);

        int a = loww[0] - 48;

        while (stoi(start) < low)
        {
            a++;
            start.push_back(static_cast<char>(a + 48));
        }

        vector<int> ans;
        int len = start.length();
        int num = stoi(start);

        for (int i = 0; i < len; i++)
            start[i] = '1';

        int inc = stoi(start);

        while (num < high)
        {
            ans.push_back(num);

            num += inc;

            if (num % 10 == 0)
            {
                start = to_string(ans[0]);
                a++;
                start.push_back(static_cast<char>(a + 48));
                num = stoi(start);

                if (num > high)
                    break;
            }
        }

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
};

int main()
{
    Solution s;

    s.sequentialDigits(1000, 13000);

    return 0;
}

/*

1291. Sequential Digits

An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

Example 1:
Input: low = 100, high = 300
Output: [123,234]

Example 2:
Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]


*/