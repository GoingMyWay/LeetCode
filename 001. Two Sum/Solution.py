class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        m_map = {}
        for i, v in enumerate(nums):
            if target - v in m_map:
                return m_map[target-v], i
            else:
                m_map[v] = i
        return []
