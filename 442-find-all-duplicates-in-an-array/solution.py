# class Solution(object):
#     def findDuplicates(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: List[int]
#         """
#         if len(nums) == 0:
#             return []

#         nums = sorted(nums)
#         result = []
        
#         for i in range(1, len(nums)):
#             if nums[i] == nums[i-1]:
#                 result.append(nums[i])
#         return result

class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        result = []
        for v in nums:
            if nums[abs(v)-1] < 0:
                result.append(abs(v))
            else:
                nums[abs(v)-1] *= -1
        return result
