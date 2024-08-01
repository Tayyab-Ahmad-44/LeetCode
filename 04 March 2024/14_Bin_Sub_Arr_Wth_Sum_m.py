from typing import List

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        m = len(intervals)
        if m == 0:
            return [newInterval]
        ans = []
        i = 0
        a = True
        
        if newInterval[1] < intervals[0][0]:
            ans.append(newInterval) 
            a = False
        
        while i < m:
            if newInterval[0] <= intervals[i][1]:
                if i == 0 and a:
                    start = newInterval[0] if newInterval[0] < intervals[i][0] else intervals[i][0]
                else: 
                    start = intervals[i][0] 

                end = newInterval[1] if newInterval[1] > intervals[i][1] else intervals[i][1]
                print(end)
                # i+=1
                while i < m and end >= intervals[i][0]:
                    # end = intervals[i][1]
                    i+=1
                i-=1
                
                end = newInterval[1] if newInterval[1] > intervals[i][1] else intervals[i][1]
                
                ans.append([start, end])
            
            else:
                ans.append(intervals[i])

            i+=1
        
        if ans[len(ans) - 1][1] < newInterval[0]:
            ans.append(newInterval)
            
        print(ans)
    
solution = Solution()

intervals = [[1, 5]]
newInterval = [0, 0]
    
solution.insert(intervals, newInterval)

                
"""
57. Insert Interval
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 
"""