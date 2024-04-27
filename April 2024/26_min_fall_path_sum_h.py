from typing import List

class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        """
        ##! Method 1: TLE
        N = len(grid)
        cache = {}
                
        def helper(r, prev_idx):
            if r == N - 1:
                return grid[r][prev_idx]
            
            if (r, prev_idx) in cache:
                return cache[(r, prev_idx)]
            
            
            res = float("inf")
            
            for c in range(N):
                if c == prev_idx:
                    continue
                res = min(res, grid[r][prev_idx] + helper(r + 1, c))                
            
            cache[(r, prev_idx)] = res
            return res
        
        res = float("inf")      
        for c in range(N):
            res = min(res, helper(0, c))

        return res
        """
        
        """
        ##! Not fully optimized -> Time: O(n^3) & Space: O(n^2) 
        N = len(grid)
        
        dp = grid[0]
        
        for r in range(1, N):
            next_dp = [float("inf")] * N
            for curr_col in range(N):
                for prev_col in range(N):
                    if curr_col == prev_col:
                        continue

                    next_dp[curr_col] = min(
                        next_dp[curr_col],
                        grid[r][curr_col] + dp[prev_col]
                    )
            
            dp = next_dp
        
        return min(dp)
        """
        
        def get_min_two(row):
            two_smallest = [] # (val, idx)
            
            for val, idx in row:
                if len(two_smallest) < 2:
                    two_smallest.append((val, idx))
                elif two_smallest[1][0] > val: # if the largest value in sorted list is greater then pop it and append a new smmaler then that
                    two_smallest.pop()
                    two_smallest.append((val, idx))
                two_smallest.sort()
            
            return two_smallest 
        
        N = len(grid)
        first_row = [(val, idx) for idx, val in enumerate(grid[0])]
        
        dp = get_min_two(first_row)
        
        for r in range(1, N):
            next_dp = [] # (val, idx)
            
            for curr_col in range(N):
                curr_val = grid[r][curr_col]
                min_val = float("inf")
                
                for prev_val, prev_col in dp:
                    if curr_col != prev_col:
                        min_val = min(min_val, curr_val + prev_val)
                
                next_dp.append((min_val, curr_col)) # maybe it will get biger then two.
                next_dp = get_min_two(next_dp) # so to make it two call this func again
            
            dp = next_dp
        
        return min([val for val, _ in dp])
                    
                    
        

sol = Solution()

grid = [[2,1,3],[5,4,6],[8,7,9]]
# grid = [[7]]

print(sol.minFallingPathSum(grid))
            
            
"""
1289. Minimum Falling Path Sum II

Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.

Example 1:
Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation: 
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.

Example 2:
Input: grid = [[7]]
Output: 7
"""