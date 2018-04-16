class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        m_map = {}
        for index, value in enumerate(numbers):
            if target - value in m_map:
                return m_map[target-value]+1, index+1
            else:
                m_map[value] = index
        return []