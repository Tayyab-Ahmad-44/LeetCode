#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int maxLength(vector<string> &arr)
    {
        int result = 0;
        dfs(arr, "", 0, result);
        return result;
    }

private:
    void dfs(const vector<string> &arr, const string &path, int idx, int &result)
    {
        if (checkUniqueness(path))
            result = max(result, static_cast<int>(path.length()));

        if (idx == arr.size() || !checkUniqueness(path)) //! If no uniqueness just return
            return;

        for (int i = idx; i < arr.size(); i++) //! Compare with all Strings in array
            dfs(arr, path + arr[i], i + 1, result);
    }

    bool checkUniqueness(const string &s)
    {
        unordered_set<char> set;
        for (char c : s)
        {
            if (set.count(c))
                return false;

            set.insert(c);
        }
        return true;
    }
};

int main()
{

    return 0;
}

/*
1239. Maximum Length of a Concatenated String with Unique Characters

You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.


Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").

Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.

Example 4: ["aa", "bb"]
 /**/