#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int LENGTH = strs.size();
        int size = 0;

        vector<vector<string>> res;
        unordered_map<string, int> check; // Use string as the key

        for (size_t i = 0; i < LENGTH; i++)
        {
            string sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end()); // Sort the string to make anagrams identical

            if (check.find(sortedStr) != check.end())
                res[check[sortedStr]].push_back(strs[i]);
            else
            {
                vector<string> push;
                push.push_back(strs[i]);
                res.push_back(push);
                check[sortedStr] = size++;
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}

/*

49. Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

*/