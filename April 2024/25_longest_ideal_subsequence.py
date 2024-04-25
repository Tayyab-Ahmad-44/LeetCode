class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        ans = 1
        for i in range(len(s)):
            myStr = s[i]
            for j in range(i+1, len(s)):
                if abs(ord(myStr[len(myStr) - 1]) - ord(s[j])) <= k:
                    myStr = myStr + s[j]
            
            if ans < len(myStr):
                ans = len(myStr)

        return ans

s = Solution()

print(s.longestIdealString("abcd", 2))
