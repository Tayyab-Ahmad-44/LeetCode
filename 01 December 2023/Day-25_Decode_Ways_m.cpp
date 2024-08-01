#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.length();
        if (n == 0 || s[0] == '0')
        {
            return 0;
        }

        vector<int> dp(2, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 1; i < n; ++i)
        {
            int ways = 0;
            if (s[i] != '0')
            {
                ways += dp[1];
            }

            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
            {
                ways += dp[0];
            }

            dp[0] = dp[1];
            dp[1] = ways;
        }

        return dp[1];
    }
};

int main()
{

    return 0;
}

/*

91. Decode Ways

A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.



Example 1:

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
Example 3:

Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").

*/

//! TLE

/*

class Solution {
public:
    int numDecodingsRecursive(string s, int index) {
        if (index == s.length()) {
            return 1; // If we reach the end of the string, one way to decode it.
        }

        if (s[index] == '0') {
            return 0; // If the current digit is '0', it cannot be decoded individually.
        }

        int ways = numDecodingsRecursive(s, index + 1); // Decode current digit individually

        if (index + 1 < s.length() && (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6'))) {
            ways += numDecodingsRecursive(s, index + 2); // Decode current and next digit together
        }

        return ways;
    }

    int numDecodings(string s) {
        return numDecodingsRecursive(s, 0);
    }
};

*/

//! Top Down

/*

class Solution {
public:
    int numDecodingsTopDown(string s, int index, vector<int>& memo) {
        if (index == s.length()) {
            return 1;
        }

        if (s[index] == '0') {
            return 0;
        }

        if (memo[index] != -1) {
            return memo[index];
        }

        int ways = numDecodingsTopDown(s, index + 1, memo);

        if (index + 1 < s.length() && (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6'))) {
            ways += numDecodingsTopDown(s, index + 2, memo);
        }

        memo[index] = ways;
        return ways;
    }

    int numDecodings(string s) {
        vector<int> memo(s.length(), -1);
        return numDecodingsTopDown(s, 0, memo);
    }
};

*/

//! Bottom UP

/*

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') {
            return 0;
        }

        vector<int> dp(2, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 1; i < n; ++i) {
            int ways = 0;
            if (s[i] != '0') {
                ways += dp[1];
            }

            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                ways += dp[0];
            }

            dp[0] = dp[1];
            dp[1] = ways;
        }

        return dp[1];
    }
};

*/