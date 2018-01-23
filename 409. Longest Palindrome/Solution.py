class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        hash_map, res = {}, 0
        for v in s:
            hash_map[v] = hash_map.get(v, 0) + 1
        
        odd_list = [v for v in hash_map.values() if v % 2 != 0]
        
        for k, v in hash_map.items():
            if v % 2 == 0:
                res += v
            else:
                res += v - 1
        
        if len(odd_list) != 0:
            return res + 1
                
        return res

