class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l_sum, s = 0, sum(nums)
        
        for i in range(len(nums)):
            if l_sum == s - l_sum - nums[i]:
                return i
            l_sum += nums[i]
        return -1

