class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        result = [1] * len(nums)
        right, left = 1, 1
        
        for i in range(len(nums)-1):
            left = left * nums[i]
            result[i+1] = result[i+1] * left
        
        for i in range(len(nums)-1, 0, -1):
            right = right * nums[i]
            result[i-1] = result[i-1] * right
        
        return result
