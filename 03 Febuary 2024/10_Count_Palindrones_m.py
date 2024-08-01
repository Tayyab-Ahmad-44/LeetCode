class Solution:
    def countSubstrings(self, s: str) -> int:
        """
            Okay, what's the smartest way to do this?
            Every one character is palindromic by itself
            We can only stop checking a character when their added string is more than halfway to the end from where they started
            aabaacabaca
            The start of one character can register other palindromes
            I mean really the only way I can think about getting all the palindromes is by adding a character to every combination and then checking if every combination is a palindrome
            That can't be the best way to do it
        """

        def countPali(st, e):
            res = 0
            while st >= 0 and e < len(s) and s[st] == s[e]:
                res += 1
                st -= 1
                e += 1
            return res

        count = 0
        for i in range(len(s)):
            st, e = i, i
            count += countPali(st, e)

            st, e = i, i + 1
            count += countPali(st, e)
            
        return count

"""
647. Palindromic Substrings

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 
    """