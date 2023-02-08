# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        count = 0
        upper_bound, lower_bound = 0, m - 1
        left_bound, right_bound = 0, n - 1
        matrix = [[0]*n for _ in range(m)]

        while (count < m * n):
            # left -> right
            if (upper_bound <= lower_bound):
                for j in range(left_bound, right_bound+1):
                    matrix[upper_bound][j] = head.val if head else -1
                    count += 1
                    head = head.next if head else head
                upper_bound += 1
            # up -> down
            if (left_bound <= right_bound):
                for i in range(upper_bound, lower_bound+1):
                    matrix[i][right_bound] = head.val if head else -1
                    count += 1
                    head = head.next if head else head
                right_bound -= 1

            # right -> left
            if (upper_bound <= lower_bound):
                for j in range(right_bound, left_bound-1, -1):
                    matrix[lower_bound][j] = head.val if head else -1
                    count += 1
                    head = head.next if head else head
                lower_bound -= 1

            # down -> up
            if (left_bound <= right_bound):
                for i in range(lower_bound, upper_bound-1, -1):
                    matrix[i][left_bound] = head.val if head else -1
                    count += 1
                    head = head.next if head else head
                left_bound += 1
        return matrix