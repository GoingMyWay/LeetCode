class Solution(object):
    def reorganizeString(self, S):
        """
        :type S: str
        :rtype: str
        """
        S = sorted(sorted(S), key=S.count)
        S[1::2], S[::2] = S[:len(S) / 2], S[len(S) / 2:]
        return ''.join(S) * (S[-1:] != S[-2:-1])
        