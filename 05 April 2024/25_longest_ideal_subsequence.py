class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        
        dp = [0] * 26
        
        for c in s:
            curr = ord(c) - ord('a')
            longest = 1
            for prev in range(26):
                if abs(curr - prev) <= k:
                    longest = max(longest, 1 + dp[prev])
            
            dp[curr] = max(longest, dp[curr])
            
        return max(dp)
                
        
        # memo = {}

        # def helper(idx, prev):
        #     if idx == len(s):
        #         return 0

        #     if (idx, prev) in memo:
        #         return memo[(idx, prev)]

        #     res = helper(idx+1, prev) 

        #     if prev == "" or abs(ord(s[idx]) - ord(prev)) <= k:
        #         res = max(res, 1+ helper(idx+1, s[i])) 

        #     memo[(idx, prev)] = res
            
        #     return res                
        
        # return helper(0, "")
        """
        ans = 1
        for i in range(len(s)):
            myStr = s[i]
            for j in range(i+1, len(s)):
                if abs(ord(myStr[len(myStr) - 1]) - ord(s[j])) <= k:
                    myStr = myStr + s[j]
            
            if ans < len(myStr):
                ans = len(myStr)

        return ans
        """
        
        

s = Solution()

s.longestIdealString("acfgbd", 2)

"""
2370. Longest Ideal Subsequence
Solved
Medium
Topics
Companies
Hint
You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:

t is a subsequence of the string s.
The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.
Return the length of the longest ideal string.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1.

 

Example 1:

Input: s = "acfgbd", k = 2
Output: 4
Explanation: The longest ideal string is "acbd". The length of this string is 4, so 4 is returned.
Note that "acfgbd" is not ideal because 'c' and 'f' have a difference of 3 in alphabet order.
Example 2:

Input: s = "abcd", k = 3
Output: 4
Explanation: The longest ideal string is "abcd". The length of this string is 4, so 4 is returned.
 

Constraints:

1 <= s.length <= 105
0 <= k <= 25
s consists of lowercase English letters.
"""