#include <iostream>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int LENGTH = s.length();

        if (LENGTH != t.length())
            return false;

        int sumS = 0;
        int sumT = 0;

        for (size_t i = 0; i < LENGTH; i++)
        {
            sumS += s[i] * ((s[i] + 1) / 2);
            sumT += t[i] * ((t[i] + 1) / 2);
        }

        return sumS == sumT;
    }
};

int main()
{

    return 0;
}

/*

242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false

*/