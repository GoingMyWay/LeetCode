class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        new_s = (.join([v for v in s if v.isalpha() or v.isdigit()])).lower()
        l, r = 0, len(new_s)-1
        while l < r:
            if new_s[l] == new_s[r]:
                l += 1
                r -= 1
            else:
                return False
        return True 
