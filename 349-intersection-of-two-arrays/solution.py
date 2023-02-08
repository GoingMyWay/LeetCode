class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
#         result, m_dict = [], {}
#         for v1 in nums1:
#             m_dict[v1] = 1
        
#         for k in m_dict.keys():
#             if k in nums2:
#                 result.append(k)
#         return result
        return list(set(nums1) & set(nums2))