class Solution(object):
    def binaryGap(self, N):
        """
        :type N: int
        :rtype: int
        """
        binary = bin(N)[2:]
        l, r, max_dist = 0, 0, 0
        for i, v in enumerate(binary):
            if v == '1':
                r = i
                if (r-l) > max_dist:
                    max_dist = r-l
                l = i
        return max_dist
