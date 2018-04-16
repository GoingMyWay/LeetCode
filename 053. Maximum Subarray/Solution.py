class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result, f = -sys.maxint, 0
        for i in xrange(len(nums)):
            f = max(f + nums[i], nums[i])
            result = max(result, f)
        
        return result
    