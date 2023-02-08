class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
#         if len(strs) == 0:
#             return ''
        
#         result = ''
        
#         win_len = min([len(v) for v in strs])
        
#         for i in xrange(1, win_len+1):
#             s = set([v[:i] for v in strs])
#             if len(s) > 1:
#                 if i == 1:
#                     return ''
#                 else:
#                     return result
#             else:
#                 result = strs[0][:i]
#         return result

        if len(strs) == 0:
            return ''
    
        result, prefix, i = '', strs[0], 1
        
        while i < len(strs):
            while strs[i].startswith(prefix) is not True:
                prefix = prefix[:-1]
                if len(prefix) == 0:
                    return ''
            i += 1
        return prefix
