class Solution:
    memo = dict()
    def fib(self, n: int) -> int:
        # if n == 0: return 0
        # if n == 1: return 1
        # return self.fib(n-1) + self.fib(n-2)
        # if n == 0 or n == 1: return n
        # if n in self.memo: return self.memo[n]
        # self.memo[n] = self.fib(n-1) + self.fib(n-2)
        # return self.memo[n]
        # if n == 0: return 0
        # dp = [0] * (n+1)
        # dp[0] = 0
        # dp[1] = 1
        # for i in range(2, n+1):
        #     dp[i] = dp[i-1] + dp[i-2]
        # return dp[n]
        if n == 0: return 0
        a, b = 0, 1
        for i in range(2, n+1):
            b, a = a + b, b
        return b