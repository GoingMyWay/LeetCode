class Solution:
    def wordPattern(self, pattern, s_str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        s_str = s_str.split()
        m_map1 = HashMap()
        m_map2 = HashMap()
        if len(pattern) != len(s_str):
            return False
        for i, s in enumerate(pattern):
            if m_map1.put(s, i) != m_map2.put(s_str[i], i):
                return False
        return True

class HashMap(dict):
    def put(self, k, v):
        if k not in self:
            self[k] = v
            return None
        else:
            ret = self.get(k)
            self[k] = v
            return ret
