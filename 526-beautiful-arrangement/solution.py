# class Solution(object):
#     def countArrangement(self, N):
#         """
#         :type N: int
#         :rtype: int
#         """
#         self.count = 0
#         self.visited = [False] * (N+1)

#         self.back_tracking(N, 1)

#         return self.count

#     def back_tracking(self, N, pos):
#         if pos > N:
#             self.count += 1
#             return

#         for i in range(1, N+1):
#             if self.visited[i] is False and (i % pos == 0 or pos % i == 0):
#                 self.visited[i] = True
#                 self.back_tracking(N, pos+1)
#                 self.visited[i] = False


# class Solution(object):
#     def countArrangement(self, N):
#         """
#         :type N: int
#         :rtype: int
#         """
#         cache = dict()
#         def solve(idx, nums):
#             if not nums: 
#                 return 1
            
#             key = idx, tuple(nums)
#             if key in cache: 
#                 return cache[key]
            
#             ans = 0
#             for i, n in enumerate(nums):
#                 if n % idx == 0 or idx % n == 0:
#                     ans += solve(idx + 1, nums[:i] + nums[i+1:])
                    
#             cache[key] = ans
#             return ans
#         return solve(1, range(1, N + 1))


cache = {}
class Solution(object):
    def countArrangement(self, N):
        def helper(i, X):
            if i == 1:
                return 1
            key = (i, X)
            if key in cache:
                return cache[key]
            total = 0
            for j in xrange(len(X)):
                if X[j] % i == 0 or i % X[j] == 0:
                    total += helper(i - 1, X[:j] + X[j + 1:])
            cache[key] = total
            return total
        return helper(N, tuple(range(1, N + 1)))

