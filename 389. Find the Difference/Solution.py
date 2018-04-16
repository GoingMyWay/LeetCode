class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        hash_map, hash_map2 = {}, {}
        for v in s:
            if v not in hash_map:
                hash_map[v] = 1
            else:
                hash_map[v] += 1
        
        for v in t:
            if v not in hash_map2:
                hash_map2[v] = 1
            else:
                hash_map2[v] += 1
        
        for k, v in hash_map2.items():
            if k not in hash_map:
                return k
            elif v != hash_map[k]:
                return k
