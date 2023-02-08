class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        need = dict()
        for v in p:
            if v not in need:
                need[v] = 0
            need[v] += 1
        window = dict()

        left, right = 0, 0
        start, length = 0, sys.maxsize
        valid = 0

        res = []

        while (right < len(s)):
            c = s[right]
            if c in need:
                if c not in window:
                    window[c] = 0
                window[c] += 1
                if window[c] == need[c]:
                    valid += 1
            
            right += 1
            while (right - left >= len(p)):
                if valid == len(need.keys()):
                    res.append(left)
                d = s[left]
                left += 1
                if d in need:
                    if window[d] == need[d]:
                        valid -= 1
                    window[d] -= 1
        return res
