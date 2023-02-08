class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:
        # counter = collections.Counter(position)
        
        cnt = 0
        for pos in position:
            if pos % 2 == 0:
                cnt += 1
        return min(cnt, len(position)-cnt)
