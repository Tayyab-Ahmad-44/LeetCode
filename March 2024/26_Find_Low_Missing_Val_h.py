class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        contains_1 = False

        # Replace negative numbers, zeros,
        # and numbers larger than n with 1s.
        # After this nums contains only positive numbers.
        for i in range(n):
            # Check whether 1 is in the original array
            if nums[i] == 1:
                contains_1 = True
            if nums[i] <= 0 or nums[i] > n:
                nums[i] = 1

        if not contains_1:
            return 1
        
        # Mark whether integers 1 to n are in nums
        # Use index as a hash key and negative sign as a presence detector.
        for i in range(n): 
            value = abs(nums[i])
            # If you meet number a in the array - change the sign of a-th element.
            # Be careful with duplicates : do it only once.
            if value == n:
                nums[0] = - abs(nums[0])
            else:
                nums[value] = - abs(nums[value])
            
        # First positive in nums is smallest missing positive integer
        for i in range(1, n):
            if nums[i] > 0:
                return i
        
        # nums[0] stores whether n is in nums
        if nums[0] > 0:
            return n

        # If nums contained all elements 1 to n
        # the smallest missing positive number is n + 1    
        return n + 1
    
"""
41. First Missing Positive

Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
 
"""