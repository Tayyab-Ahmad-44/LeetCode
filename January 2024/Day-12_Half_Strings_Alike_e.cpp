#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        if (s.length() % 2 != 0)
            return false;

        unordered_set<char> vowels = {
            'a',
            'e',
            'i',
            'o',
            'u',
        };

        int left = 0, right = s.length() - 1;
        int leftCount = 0, rightCount = 0;

        while (left < right)
        {
            if (vowels.find(tolower(s[left])) != vowels.end())
                leftCount++;
            if (vowels.find(tolower(s[right])) != vowels.end())
                rightCount++;

            left++;
            right--;
        }

        return leftCount == rightCount;
    }
};

int main()
{
    Solution s;

    cout << s.halvesAreAlike("book");
    cout << s.halvesAreAlike("textbook");

    return 0;
}

/*

1704. Determine if String Halves Are Alike
Hint
You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.



Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.


*/