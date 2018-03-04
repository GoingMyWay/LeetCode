class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        for idx, col in enumerate(s):
            result *= 26
            result += ord(col) - ord(A) + 1
            
        return result

