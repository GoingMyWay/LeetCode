class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:

        self.memo = dict()
        
        def dp(coins, amount):
            if amount == 0: return 0
            if amount < 0: return -1

            if amount in self.memo: return self.memo[amount]

            res = sys.maxsize
            for coin in coins:
                sub_problem = dp(coins, amount - coin)
                if sub_problem == -1: continue
                res = min(res, sub_problem + 1)
            self.memo[amount] = -1 if res == sys.maxsize else res
            return self.memo[amount]
        
        return dp(coins, amount)
