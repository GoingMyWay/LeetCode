class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        k += 1
        self.src, self.dst = src, dst
        self.memo = [[-888]*(k+1) for _ in range(n)]
        self.indegree = dict()

        for f in flights:
            _from, _to, _price = f
            if _to not in self.indegree:
                self.indegree[_to] = [(_from, _price)]
            else:
                self.indegree[_to].append((_from, _price))
        
        def dp(s, k):
            if s == self.src: return 0
            if k == 0: return -1
            if self.memo[s][k] != -888: return self.memo[s][k]

            res = sys.maxsize
            if s in self.indegree:
                for _from, _price in self.indegree[s]:
                    sub_problem = dp(_from, k-1)
                    if sub_problem != -1:
                        res = min(res, sub_problem + _price)
            self.memo[s][k] = -1 if res == sys.maxsize else res
            return self.memo[s][k]
        return dp(dst, k)
