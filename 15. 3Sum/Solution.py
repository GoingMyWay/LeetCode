# class Solution(object):
#     def threeSum(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: List[List[int]]
#         """
#         res, sorted_nums = [], sorted(nums)
        
#         for i, v in enumerate(sorted_nums[:-2]):
#             m_map = {}
#             begin, end = i+1, len(sorted_nums)-1
#             while begin < end:
#                 if v == 0 or v != nums[i-1]:
#                     if sorted_nums[begin] + sorted_nums[end] == -v:
#                         res.append([v, sorted_nums[begin], sorted_nums[end]])
#                         begin, end = begin + 1, end - 1
                        
#                         while begin < end and sorted_nums[begin] == sorted_nums[begin-1]:
#                             begin += 1
#                         while begin < end and sorted_nums[end] == sorted_nums[end+1]:
#                             end -= 1
                        
#                     if sorted_nums[begin] + sorted_nums[end] > -v:
#                         end -= 1
#                     else:
#                         begin += 1
                    
#         return res

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums, result, i = sorted(nums), [], 0
        while i < len(nums) - 2:
            if i == 0 or nums[i] != nums[i - 1]:
                j, k = i + 1, len(nums) - 1
                while j < k:
                    if nums[i] + nums[j] + nums[k] < 0:
                        j += 1
                    elif nums[i] + nums[j] + nums[k] > 0:
                        k -= 1
                    else:
                        result.append([nums[i], nums[j], nums[k]])
                        j, k = j + 1, k - 1
                        while j < k and nums[j] == nums[j - 1]:
                            j += 1
                        while j < k and nums[k] == nums[k + 1]:
                            k -= 1
            i += 1
        return result
