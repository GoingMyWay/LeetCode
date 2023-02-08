class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums_v = sorted(nums)
        i, j = 0, len(nums) - 1
        i_found, j_found = False, False
        
        while i < j:
            if nums_v[i] != nums[i] and not i_found:
                i_found = True
            if nums_v[j] != nums[j] and not j_found:
                j_found = True
                
            if i_found and j_found:
                return j - i + 1
            if not i_found:
                i += 1
            if not j_found:
                j -= 1
        
        return 0

# class Solution(object):
#     def findUnsortedSubarray(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
#         l, r = len(nums), 0
#         nums_v = sorted(nums)
#         for k in xrange(len(nums)):
#             if nums[k] != nums_v[k]:
#                 l, r = min(k, l), max(k, r)

#         return r - l + 1 if r - l >= 0 else 0
