class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.results = []
        result = []
        for index, value in enumerate(nums):
            result.append(value)
            self.back_tracking(result, nums[:index]+nums[index+1:])
            result.pop()
        return self.results

    def back_tracking(self, result, nums):
        # back to previous state
        if len(nums) == 0:
            if result[:] not in self.results:
                self.results.append(result[:])
            return
    
        for index, value in enumerate(nums):
            result.append(value)
            self.back_tracking(result, nums[:index]+nums[index+1:])
            result.pop()
