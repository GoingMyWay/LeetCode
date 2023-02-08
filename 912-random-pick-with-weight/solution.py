class Solution:

    def __init__(self, w: List[int]):
        n = len(w)
        self.pre_sum = [0] * (n+1)
        for i in range(1, n+1):
            self.pre_sum[i] = self.pre_sum[i-1] + w[i-1]

    def pickIndex(self) -> int:
        import random 
        target = random.randint(1, self.pre_sum[-1])
        return self.left_bound(self.pre_sum, target) - 1

    def left_bound(self, nums, target):
        left, right = 1, len(nums) - 1
        while (left <= right):
            mid = left + (right - left) // 2
            if (nums[mid] > target):
                right = mid - 1
            elif (nums[mid] < target):
                left = mid + 1
            elif (nums[mid] == target):
                right = mid - 1
            
        # if left == len(nums): return -1
        # return left if nums[left] == target else -1
        return left

# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()