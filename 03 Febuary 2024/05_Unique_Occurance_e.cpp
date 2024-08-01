#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> freq(26, 0);

        for (int i = 0; i < s.length(); i++)
            freq[s[i] - 'a']++;

        for (int i = 0; i < s.length(); i++)
            if (freq[s[i] - 'a'] == 1)
                return i;

        return -1;
    }
};

int main()
{
    Solution s;

    cout << s.firstUniqChar("leetcode") << endl;

    cout << s.firstUniqChar("loveleetcode") << endl;

    cout << s.firstUniqChar("aabb");

    return 0;
}

/*

387. First Unique Character in a String

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1

*/