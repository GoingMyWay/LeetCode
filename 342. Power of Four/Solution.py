class Solution(object):
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num & (num-1) != 0:
            return False
        if num & 0x55555555 > 0:
            return True
        return False
