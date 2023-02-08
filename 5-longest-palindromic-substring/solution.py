class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = ""
        for i in range(len(s)):
            r1 = self.palindrome(s, i, i)
            r2 = self.palindrome(s, i, i+1)
            res = res if len(res) > len(r1) else r1
            res = res if len(res) > len(r2) else r2
        return res

    def palindrome(self, s, left, right):
        while (left >= 0 and right < len(s) and s[left] == s[right]):
            left -= 1
            right += 1
        
        return s[left+1:right]
        