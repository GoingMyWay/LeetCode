class Solution(object):
    def findLengthOfLCIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        
        left, right, max_len, index = 0, 0, 1, 1
        
        while index < len(nums):
            
            if nums[index] > nums[index-1]:
                right = index
            else:
                left, right = index, index
            
            if right - left + 1 >= max_len:
                max_len = right - left + 1
            index += 1
    
        return max_len