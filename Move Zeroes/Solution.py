class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
#         i = 0
#         for j in range(len(nums)):
#             if nums[j] != 0:
#                 nums[i] = nums[j]
#                 i += 1
                
#         for index in range(i, len(nums)):
#             nums[index] = 0
        
#         zero_count = 0
#         for v in nums:
#             if v == 0:
#                 zero_count += 1
        
#         none_zero_list = []
#         for v in nums:
#             if v != 0:
#                 none_zero_list.append(v)
        
#         for i in range(zero_count):
#             none_zero_list.append(0)
        
#         for i in range(len(nums)):
#             nums[i] = none_zero_list[i]

        i = 0
        for j in range(len(nums)):
            if nums[j] != 0:
                nums[i] = nums[j]
                i += 1
        
        for index in range(i, len(nums)):
            nums[index] = 0
        
        