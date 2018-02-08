class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        l, r, s = 0, len(s)-1, list(s)
        vowels = set([a, e, i, o, u, A, E, I, O, U])
        while l < r:
            if s[l] in vowels and s[r] in vowels:
                s[r], s[l] = s[l], s[r]
                r -= 1
                l += 1
            elif s[l] in vowels:
                r -= 1
            elif s[r] in vowels:
                l += 1
            else:
                r -= 1
                l += 1
                
        return .join(s)

