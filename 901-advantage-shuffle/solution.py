class Solution:
    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # 田忌赛马问题
        hq = []
        # 大顶堆
        for i, num in enumerate(nums2):
            heapq.heappush(hq, (-num, i))
        nums1.sort()
        # 双指针
        left, right = 0, len(nums1) - 1
        res = [0] * len(nums1)
        while hq:
            max_num, idx = heapq.heappop(hq)
            max_sum = -max_num
            if max_sum < nums1[right]:
                res[idx] = nums1[right]
                right -= 1
            else:
                res[idx] = nums1[left]
                left += 1
        return res
