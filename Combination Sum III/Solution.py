class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        result = []
        def search(start, cnt, sums, nums):
            if cnt > k or sums > n:
                return
            if cnt == k and sums == n:
                result.append(nums)
                
            for _start in range(start+1, 10):
                search(_start, cnt+1, sums+_start, nums+[_start])
        
        search(0, 0, 0, [])
        
        return result
