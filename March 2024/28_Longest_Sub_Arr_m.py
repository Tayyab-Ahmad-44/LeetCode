from typing import List

class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        ans = 0

        count = 0

        left = right = 0

        freq = {}

        for right in range(len(nums)):
            freq[nums[right]] = freq.get(nums[right], 0) + 1

            if freq[nums[right]] > k:
                freq[nums[left]] -= 1
                left += 1

                for i in range(left, right):
                    if freq[nums[i]] > k:
                        while freq[nums[left]] <= k:
                            freq[nums[left]] -= 1
                            left += 1
                        while freq[nums[left]] > k:
                            freq[nums[left]] -= 1
                            left += 1

                    i = left
                
            ans = max(ans, right - left + 1)

        return ans
    
    
"""
2958. Length of Longest Subarray With at Most K Frequency
Medium

You are given an integer array nums and an integer k.

The frequency of an element x is the number of times it occurs in an array.

An array is called good if the frequency of each element in this array is less than or equal to k.

Return the length of the longest good subarray of nums.

A subarray is a contiguous non-empty sequence of elements within an array.


Example 1:
Input: nums = [1,2,3,1,2,3,1,2], k = 2
Output: 6
Explanation: The longest possible good subarray is [1,2,3,1,2,3] since the values 1, 2, and 3 occur at most twice in this subarray. Note that the subarrays [2,3,1,2,3,1] and [3,1,2,3,1,2] are also good.
It can be shown that there are no good subarrays with length more than 6.

Example 2:
Input: nums = [1,2,1,2,1,2,1,2], k = 1
Output: 2
Explanation: The longest possible good subarray is [1,2] since the values 1 and 2 occur at most once in this subarray. Note that the subarray [2,1] is also good.
It can be shown that there are no good subarrays with length more than 2.

Example 3:
Input: nums = [5,5,5,5,5,5,5], k = 4
Output: 4
Explanation: The longest possible good subarray is [5,5,5,5] since the value 5 occurs 4 times in this subarray.
It can be shown that there are no good subarrays with length more than 4.
 
"""