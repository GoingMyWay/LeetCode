class Solution(object):
    def dominantIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_v = max(nums)
        max_index = nums.index(max_v)

        for v in nums:
            if v != max_v and max_v < v * 2:
                return -1
        return max_index

