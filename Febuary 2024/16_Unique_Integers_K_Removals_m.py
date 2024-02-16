class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        freq = {}

        # Initialize frequency dictionary
        for num in arr:
            freq[num] = freq.get(num, 0) + 1

        vals = list(freq.values())  # Extracting frequency values
        vals.sort()  # Sorting frequency values

        n = 0
        for val in vals:
            if k >= val:
                k -= val
                n += 1
            else:
                break

        return len(vals) - n  # Return the number of remaining unique integers


"""
1481. Least Number of Unique Integers after K Removals

Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

Example 1:
Input: arr = [5,5,4], k = 1
Output: 1
Explanation: Remove the single 4, only 5 is left.

Example 2:
Input: arr = [4,3,1,1,3,3,2], k = 3
Output: 2
Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.
 
"""
