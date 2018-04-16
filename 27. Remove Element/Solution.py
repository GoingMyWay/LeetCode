class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i = 0
        for j in xrange(len(nums)):
            if nums[j] != val:
                nums[i] = nums[j]
                i += 1
        return i
