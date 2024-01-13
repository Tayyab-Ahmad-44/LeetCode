#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    //! Good but it can be much better
    /*int minSteps(string s, string t)
    {

        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;
        int res = 0;
        int LENGTH = s.length();

        for (int i = 0; i < LENGTH; i++)
            sMap[s[i]]++;

        for (int i = 0; i < LENGTH; i++)
        {
            tMap[t[i]]++;
            if (sMap.find(t[i]) == sMap.end())
                res++;
            else if (sMap[t[i]] < tMap[t[i]])
            {
                res++;
            }
        }

        return res;
    }/**/

    int minSteps(string s, string t)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int occ[26] = {0};

        for (char character : s)
            occ[character - 'a']++;

        for (char character : t)
            occ[character - 'a']--;

        int res = 0;
        for (int i = 0; i < 26; i++)
            res += abs(occ[i]);

        return res / 2;
    }
};

int main()
{

    return 0;
}

/*

1347. Minimum Number of Steps to Make Two Strings Anagram

You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.



Example 1:

Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.
Example 2:

Input: s = "leetcode", t = "practice"
Output: 5
Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.
Example 3:

Input: s = "anagram", t = "mangaar"
Output: 0
Explanation: "anagram" and "mangaar" are anagrams.

*/