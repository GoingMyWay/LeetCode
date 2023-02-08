class Solution(object):
    def largeGroupPositions(self, S):
        """
        :type S: str
        :rtype: List[List[int]]
        """
        l, r = 0, 0
        result = []
        while True:
            if S[l] == S[r]:
                r += 1
                if r == len(S) and r - l >= 3:  # 'aaa'
                    result.append([l, r-1])
                    break
            else:
                if r - l >= 3:  # 'abbxxxxzzy'
                    result.append([l, r-1])  
                l, r = r, r
            if r == len(S):
                break
        return result
