class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        m_map = {}
        for v in nums:
            m_map[v] = m_map.get(v, 0) + 1
        res = sorted(m_map.items(), key=lambda v:v[1], reverse=True)[:k]
        return [v for v, _ in res]

