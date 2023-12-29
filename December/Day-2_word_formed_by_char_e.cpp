#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        vector<int> counts(26, 0);

        // Count characters in 'chars'
        for (char c : chars)
        {
            counts[c - 'a']++;
        }

        int ans = 0;

        for (string word : words)
        {
            vector<int> wordCount(26, 0);

            // Count characters in the current word
            for (char c : word)
            {
                wordCount[c - 'a']++;
            }

            bool good = true;

            // Check if the word is "good"
            for (int i = 0; i < 26; i++)
            {
                if (counts[i] < wordCount[i])
                {
                    good = false;
                    break;
                }
            }

            if (good)
            {
                ans += word.size();
            }
        }

        return ans;
    }
};

int main()
{
    vector<string> words = {"cat", "bt", "hat", "tree"};
    string chars = "atach";

    Solution s;

    int ans = s.countCharacters(words, chars);

    cout << ans;
}
