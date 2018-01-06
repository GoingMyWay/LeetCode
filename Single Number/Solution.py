class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        m_dict = {}
        
        for index, value in enumerate(nums):
            if value in m_dict:
                m_dict[value] += 1
            else:
                m_dict[value] = 1
        for key, value in m_dict.items():
            if value == 1:
                return key

        