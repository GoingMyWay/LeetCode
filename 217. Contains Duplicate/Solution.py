class Solution:
    # @param {integer[]} nums
    # @return {boolean}
    def containsDuplicate(self, nums):
        if len(nums) == 0 or len(nums) == 1:
            return False
        if len(nums) == len(set(nums)):
            return False
        return True