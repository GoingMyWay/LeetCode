class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_len, dp = 0, [0] * len(nums)
        
        for i in range(len(nums)):
            max_v = 0 
            for j in range(0, i):
                if nums[i] > nums[j]:
                    max_v = max(max_v, dp[j])
            dp[i] = max_v + 1
            max_len = max(dp[:i+1])
        return max_len
