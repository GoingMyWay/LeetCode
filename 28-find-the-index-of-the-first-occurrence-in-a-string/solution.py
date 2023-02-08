class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if len(needle) == 0:
            return 0
        if len(needle) > len(haystack):
            return -1
        i, j = 0, 0
        while i <= len(haystack) - len(needle):
            j = 0
            while j < len(needle):
                if haystack[i+j] != needle[j]:
                    break
                j += 1
            
            if j == len(needle):
                return i
            i += 1
        return  -1