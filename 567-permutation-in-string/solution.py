class Solution:
    def checkInclusion(self, t: str, s: str) -> bool:
        need = dict()
        for v in t:
            if v not in need:
                need[v] = 0
            need[v] += 1
        window = dict()

        left, right = 0, 0
        start, length = 0, sys.maxsize
        valid = 0

        while (right < len(s)):
            c = s[right]
            if c in need:
                if c not in window:
                    window[c] = 0
                window[c] += 1
                if window[c] == need[c]:
                    valid += 1
            
            right += 1
            while (right - left >= len(t)):
                if valid == len(need.keys()):
                    return True
                d = s[left]
                left += 1
                if d in need:
                    if window[d] == need[d]:
                        valid -= 1
                    window[d] -= 1
        return False
