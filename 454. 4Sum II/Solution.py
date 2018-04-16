class Solution(object):
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        count, m_map = 0, {}
        for a in A:
            for b in B:
                if a + b in m_map:
                    m_map[a+b] += 1
                else:
                    m_map[a+b] = 1
        
        for c in C:
            for d in D:
                if -(c + d) in m_map:
                    count += m_map[-c-d]
        
        return count
