# class Solution(object):
#     def findPairs(self, nums, k):
#         """
#         :type nums: List[int]
#         :type k: int
#         :rtype: int
#         """
#         if len(nums) == 0 or k < 0:
#             return 0
        
#         count, m_map = 0, {}
        
#         for v in nums:
#             m_map[v] = m_map.get(v, 0) + 1
        
#         for key in m_map.keys():
#             if k == 0:
#                 if m_map.get(k+key, 0) >= 2:
#                     count += 1
#             else:
#                 if k+key in m_map:
#                     count += 1
#         return count


class Solution(object):
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if k < 0:
            return 0
        
        c = collections.Counter(nums)
        return sum(c[k+v] > 1 - bool(k) for v in c.keys())
