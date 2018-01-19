class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        hash_map, index_map = collections.Counter(s), {}
        for index, v in enumerate(s):
            index_map[v] = index
        
        for v in s:
            if hash_map[v] == 1:
                return index_map[v]
        return -1