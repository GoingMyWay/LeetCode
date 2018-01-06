class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        outputs = []
        self.back_tracking(nums, 0, [], outputs)
        return outputs
        
    def back_tracking(self, nums, index, path, outputs):
        outputs.append(path)
        for i in xrange(index, len(nums)):
            self.back_tracking(nums, i+1, path+[nums[i]], outputs)
