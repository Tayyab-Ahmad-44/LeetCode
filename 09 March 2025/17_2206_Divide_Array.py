from typing import List
from collections import Counter


class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        # Naive Method
        """
        all_items = set(nums)

        count_dict = {}
        
        for num in nums:
            if num in count_dict:
                count_dict[num] += 1
            else:
                count_dict[num] = 1

        for num in all_items:
            if count_dict[num] % 2 != 0:
                return False

        return True
        """

        # Efficient Method
        counter = Counter(nums)

        for count in counter.values():
            if count % 2 == 1:
                return False
            
        return True
    


"""
2206. Divide Array Into Equal Pairs
Easy
s
You are given an integer array nums consisting of 2 * n integers.

You need to divide nums into n pairs such that:

Each element belongs to exactly one pair.
The elements present in a pair are equal.
Return true if nums can be divided into n pairs, otherwise return false.

 

Example 1:
Input: nums = [3,2,3,2,2,2]
Output: true
Explanation: 
There are 6 elements in nums, so they should be divided into 6 / 2 = 3 pairs.
If nums is divided into the pairs (2, 2), (3, 3), and (2, 2), it will satisfy all the conditions.

Example 2:
Input: nums = [1,2,3,4]
Output: false
Explanation: 
There is no way to divide nums into 4 / 2 = 2 pairs such that the pairs satisfy every condition.
 

Constraints:
nums.length == 2 * n
1 <= n <= 500
1 <= nums[i] <= 500
"""