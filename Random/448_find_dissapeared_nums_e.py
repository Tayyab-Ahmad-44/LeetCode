class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        """
        ans = []

        mySet = set()

        for num in nums:
            mySet.add(num)

        for i in range(1, len(nums)+1):
            if i not in mySet:
                ans.append(i)

        return ans
        """

        #! O(n) time and O(1) space
        return set(range(1, len(nums) + 1)) - set(nums)
"""
448. Find All Numbers Disappeared in an Array
Easy

Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums. 

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:
Input: nums = [1,1]
Output: [2]
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
 

Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.



"""