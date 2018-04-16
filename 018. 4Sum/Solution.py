class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        result = []
        for i in xrange(len(nums)-3):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            result = self.threeSum(nums[i+1:], nums[i], target-nums[i], result)
        return result
    
    def threeSum(self, nums, v, target, result):
        for i in xrange(len(nums)-2):
            left, right = i + 1, len(nums) - 1
            
            if i > 0 and nums[i] == nums[i-1]:
                continue
            
            while left < right:
                sum_v = nums[left] + nums[right]
                
                if sum_v > target - nums[i]:
                    right -= 1
                elif sum_v < target - nums[i]:
                    left += 1
                else:
                    result.append([v, nums[i], nums[left], nums[right]])
                    left, right = left +1, right - 1
                    
                    while left < right and nums[left] == nums[left-1]:
                        left += 1
                    while left < right and nums[right] == nums[right+1]:
                        right -= 1
        
        return result
