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
        # mark all the indexes negative based on the nums given in array, then you 
        # will be left with the positive indxes means that they are not in the array
        # so append it to the answer
        
        for num in nums:
            i = abs(num) - 1
            nums[i] = -1 * abs(nums[i])

        ans = []
        for i in range(len(nums)):
            if nums[i] > 0:
                ans.append(i + 1)

        return ans
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