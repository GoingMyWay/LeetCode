class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left, right = 0, len(numbers) - 1
        while (left < right):
            sum_v = numbers[left] + numbers[right]
            if sum_v == target:
                return [left + 1, right + 1]
            if sum_v < target:
                left += 1
            else:
                right -= 1
        return [-1, -1]
