#include <iostream>

using namespace std;

class Solution
{
public:
    string largestGoodInteger(string num)
    {
        int res = -1;

        for (size_t i = 0; i < num.length() - 2; i++)
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2])
            {
                int nums = num[i] - 48;
                res = max(res, nums);
            }

        if (res != -1)
        {
            return (to_string(res) + to_string(res) + to_string(res));
        }
        else
            return "";
    }
};

int main()
{
    Solution s;

    cout << s.largestGoodInteger("677713339");

    return 0;
}

/**
2264. Largest 3-Same-Digit Number in String

You are given a string num representing a large integer. An integer is good if it meets the following conditions:

It is a substring of num with length 3.
It consists of only one unique digit.
Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:

A substring is a contiguous sequence of characters within a string.
There may be leading zeroes in num or a good integer.


Example 1:

Input: num = "6777133339"
Output: "777"
Explanation: There are two distinct good integers: "777" and "333".
"777" is the largest, so we return "777".
Example 2:

Input: num = "2300019"
Output: "000"
Explanation: "000" is the only good integer.
Example 3:

Input: num = "42352338"
Output: ""
Explanation: No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.

*/