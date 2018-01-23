class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        hash_map = {}
        while True:
            n = sum([int(v)**2 for v in str(n)])
            if n == 1:
                return True
            if n not in hash_map:
                hash_map[n] = 1
            else:
                return False

