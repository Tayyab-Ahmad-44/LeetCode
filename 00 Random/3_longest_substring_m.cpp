#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();                     //*     a b c a b c b b
        int maxLength = 0;                      //*     ^     ^
        vector<int> charIndex(128, -1);         //?     0      3
        int left = 0;                           //!        3 > 0
                                                //*              so left will be updated and equal to 0 + 1
        for (int right = 0; right < n; right++) //?     and next occurance of a will be set to 3
        {
            if (charIndex[s[right]] >= left)    //! means if current char index is greater then previously stored index of that character. It will be greater if that char comes again
                left = charIndex[s[right]] + 1; //! Updating the left pointer if element come again

            charIndex[s[right]] = right; //! Storing current index for character that occue
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main()
{

    return 0;
}