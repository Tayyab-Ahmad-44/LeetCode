#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        int frontWord1Pointer = 0, frontWord2Pointer = 0;
        int frontString1Pointer = 0, frontString2Pointer = 0;

        int backWord1Pointer = word1.size() - 1, backWord2Pointer = word2.size() - 1;
        int backString1Pointer = word1[backWord1Pointer].size() - 1, backString2Pointer = word2[backWord2Pointer].size() - 1;

        while (frontWord1Pointer <= backWord1Pointer && frontWord2Pointer <= backWord2Pointer)
        {
            if ((word1[frontWord1Pointer][frontString1Pointer++] != word2[frontWord2Pointer][frontString2Pointer++]) || (word1[backWord1Pointer][backString1Pointer--] != word2[backWord2Pointer][backString2Pointer--]))
                return false;

            if (backString1Pointer < 0)
            {
                if (backWord1Pointer > 0)
                {
                    backWord1Pointer--;
                    backString1Pointer = word1[backWord1Pointer].size() - 1;
                }
            }

            if (backString2Pointer < 0)
            {
                if (backWord2Pointer > 0)
                {
                    backWord2Pointer--;
                    backString2Pointer = word2[backWord2Pointer].size() - 1;
                }
            }

            if (frontString1Pointer == word1[frontWord1Pointer].size())
            {
                frontWord1Pointer++;
                frontString1Pointer = 0;
            }

            if (frontString2Pointer == word2[frontWord2Pointer].size())
            {
                frontWord2Pointer++;
                frontString2Pointer = 0;
            }
        }

        return true;
    }
};

int main()
{
    vector<std::string> word1 = {"fvnzyxfm", "vtsezl"};
    vector<std::string> word2 = {"f", "v", "nzyx", "fmvt", "sez", "l"};

    Solution s;

    cout << s.arrayStringsAreEqual(word1, word2);

    return 0;
}