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
        std::array<int, 26> charCount1 = {};
        std::array<int, 26> charCount2 = {};

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