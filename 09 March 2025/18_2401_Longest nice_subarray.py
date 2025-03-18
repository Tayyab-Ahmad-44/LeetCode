from typing import List


class Solution:
    def is_nice(self, arr: List[int]) -> bool:
        for i in range(len(arr)):
            for j in range(i+1, len(arr)):
                if arr[i] & arr[j] != 0:
                    return False
        return True
        
    
    def longestNiceSubarray(self, nums: List[int]) -> int:
        """"""

        n = len(nums)
        res = 1
        
        for i in range(n):
            for j in range(i+1, n):
                if self.is_nice(nums[i:j+1]):
                    if j-i+1 > res:
                        res = j-i+1
                        
        return res
    
    
class Solution_2:
    def longestNiceSubarray(self, nums: list[int]) -> int:
        # Binary search for the longest nice subarray length
        left, right = 0, len(nums)
        result = (
            1  # Minimum answer is 1 (as subarrays of length 1 are always nice)
        )

        while left <= right:
            length = left + (right - left) // 2
            if self._can_form_nice_subarray(length, nums):
                result = length  # Update the result
                left = length + 1  # Try to find a longer subarray
            else:
                right = length - 1  # Try a shorter length

        return result

    def _can_form_nice_subarray(self, length: int, nums: list[int]) -> bool:
        if length <= 1:
            return True  # Subarray of length 1 is always nice

        # Try each possible starting position for subarray of given length
        for start in range(len(nums) - length + 1):
            bit_mask = 0  # Tracks the bits used in the current subarray
            is_nice = True

            # Check if the subarray starting at 'start' with 'length' elements is nice
            for pos in range(start, start + length):
                # If current number shares any bits with existing mask,
                # the subarray is not nice
                if bit_mask & nums[pos] != 0:
                    is_nice = False
                    break
                bit_mask |= nums[pos]  # Add current number's bits to the mask

            if is_nice:
                return True  # Found a nice subarray of the specified length

        return False  # No nice subarray of the given length exists


"""
2401. Longest Nice Subarray
Medium

You are given an array nums consisting of positive integers.

We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.

Return the length of the longest nice subarray.

A subarray is a contiguous part of an array.

Note that subarrays of length 1 are always considered nice.

 

Example 1:
Input: nums = [1,3,8,48,10]
Output: 3
Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.


Example 2:
Input: nums = [3,1,5,11,13]
Output: 1
Explanation: The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.
 

Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 109
"""