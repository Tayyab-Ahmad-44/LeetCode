#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool closeStrings(std::string word1, std::string word2)
    {
        array<int, 26> charCount1 = {};
        array<int, 26> charCount2 = {};

        for (char c : word1)
            ++charCount1[c - 'a'];

        for (char c : word2)
            ++charCount2[c - 'a'];

        for (int i = 0; i < 26; ++i)
        {
            bool charPresentWord1 = charCount1[i] > 0;
            bool charPresentWord2 = charCount2[i] > 0;

            if ((charPresentWord1 && !charPresentWord2) || (!charPresentWord1 && charPresentWord2))
                return false;
        }

        sort(charCount1.begin(), charCount1.end());
        sort(charCount2.begin(), charCount2.end());

        for (int i = 0; i < 26; ++i)
            if (charCount1[i] != charCount2[i])
                return false;

        return true;
    }
};

int main()
{
    Solution s;

    cout << s.closeStrings("abc", "bca") << endl;
    cout << s.closeStrings("a", "aa") << endl;
    cout << s.closeStrings("cabbba", "abbccc") << endl;
    cout << s.closeStrings("cabbba", "aabbss") << endl;

    return 0;
}

/*

1657. Determine if Two Strings Are Close

Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.



Example 1:

Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"
Example 2:

Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
Example 3:

Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"


*/