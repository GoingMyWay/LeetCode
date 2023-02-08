class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        data = list(zip(ages, scores))
        data.sort()
        
        dp = [e[1] for e in data]
        for i in range(len(data)):
            score = data[i][1]
            for j in range(i):
                if data[j][1] <= score:
                    dp[i] = max(dp[i], dp[j]+score)
        return max(dp)
