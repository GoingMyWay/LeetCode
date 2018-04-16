class Solution(object):
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        perfect = set([6, 28, 496, 8128, 33550336, 8589869056])
        return num in perfect
