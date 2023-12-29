#include <iostream>

using namespace std;

int speedUp = []
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string largestOddNumber(string num)
    {
        for (int idx = num.length(); idx > -1; idx--)
        {
            int number = num[idx] - 48;

            if (number % 2 != 0)
                return num.substr(0, idx + 1);
        }

        return "";
    }
};

int main()
{
    Solution s;

    cout << s.largestOddNumber("6352");

    return 0;
}

/*
1903. Largest Odd Number in String

You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.


Example 1:

Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
Example 2:

Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".
Example 3:

Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.

*/