class Solution(object):
    def wordPattern(self, pattern, s_str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        return map(pattern.find, pattern) == map(s_str.split().index, s_str.split())

