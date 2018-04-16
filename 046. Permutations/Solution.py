class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.results = []
        result = []
        for index, value in enumerate(nums):
            result.append(value)
            self.back_tracking(result, nums[:index]+nums[index+1:])
            result.remove(value)
        return self.results

    def back_tracking(self, result, nums):
        # back to previous state
        if len(nums) == 0:
            self.results.append(result[:])
            return

        # move onward
        for index, value in enumerate(nums):
            result.append(value)
            self.back_tracking(result, nums[:index]+nums[index+1:])
            result.remove(value)
