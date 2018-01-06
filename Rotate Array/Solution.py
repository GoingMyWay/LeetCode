class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        k %= len(nums)
        
        aux = nums[-k:]
        i = len(nums) - 1 - k
        while i >= 0:
            nums[i+k] = nums[i]
            i -= 1

        for j in range(len(aux)):
            nums[j] = aux[j]
