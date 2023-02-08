# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @return {boolean}
    def isPalindrome(self, head):
        L = []
        while head != None:
            L.append(head.val)
            head = head.next
        length = len(L)
        i = 0
        while i < length:
            if L[i] != L[length-i-1]:
                return False
            i += 1
        return True
        