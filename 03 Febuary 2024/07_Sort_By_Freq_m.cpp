#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_map<char, int> freq;
        priority_queue<pair<int, char>> maxHeap;
        int LENGTH = s.length();
        string ans = "";

        for (int i = 0; i < LENGTH; i++)
            freq[s[i]]++;

        for (const auto &iter : freq)
            maxHeap.push({iter.second, iter.first});

        while (!maxHeap.empty())
        {
            auto top = maxHeap.top();

            for (int i = 0; i < top.first; i++)
                ans.push_back(top.second);

            maxHeap.pop();
        }

        return ans;
    }
};

int main()
{
    Solution s;

    string res = s.frequencySort("tree");

    cout << res;

    return 0;
}

/*

451. Sort Characters By Frequency

Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

Example 1:
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:
Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.


*/