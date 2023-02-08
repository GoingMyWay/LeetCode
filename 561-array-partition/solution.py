class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_min_v = 0
        nums.sort()
        
        for i in range(0, len(nums), 2):
            max_min_v += min(nums[i], nums[i+1])
        return max_min_v
        