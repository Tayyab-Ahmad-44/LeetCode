from typing import List

class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
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
        
        
        # def helper(row, prev_idx, summ):
        #     nonlocal res
        #     if row == r:
        #         res = min(res, summ)
        #         return 
        #     for i in range(c):
        #         if i == prev_idx:
        #             continue
        #         helper(row + 1, i, summ + grid[row][i])
                
        # helper(0, -1, 0)
        # return res
                

sol = Solution()

grid = [[2,1,3],[5,4,6],[8,7,9]]
# grid = [[7]]

print(sol.minFallingPathSum(grid))
            