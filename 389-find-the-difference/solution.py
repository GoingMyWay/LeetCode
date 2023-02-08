class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        map_1, map_2 = collections.Counter(s), collections.Counter(t)
        
        for k, v in map_2.items():
            if k not in map_1:
                return k
            elif v != map_1[k]:
                return k
