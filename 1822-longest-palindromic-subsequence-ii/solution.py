class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        memo = {}
        
        @functools.lru_cache(None)
        def helper(i, j, prev_char):
            if i >= j:
                return 0
            if s[i] == s[j] and s[i] != prev_char:
                return 2 + helper(i+1, j-1, s[i])
            return max(helper(i+1, j, prev_char), helper(i, j-1, prev_char))

        res = helper(0, len(s) - 1, '@')
        helper.cache_clear()
        return res
        
