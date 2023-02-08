class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        char_dict = collections.defaultdict(list)
        for index, c in enumerate(ring):
            char_dict[c].append(index)
        
        m = len(ring)
        n = len(key)

        # d[i][j]: 当指针指向ring[i]时，拼写key[j:]的最小步数
        # base case: d[i][n] = 0
        d = [[0] * (n + 1) for i in range(m)]

        for j in range(n - 1, -1, -1):
            for i in range(m):
                for k in char_dict[key[j]]:
                    step = min(abs(k - i), abs(m - abs(k - i)))
                    d_i_j = d[k][j + 1] + step + 1
                    d[i][j] = min(d[i][j], d_i_j) if d[i][j] else d_i_j
        
        return d[0][0]
