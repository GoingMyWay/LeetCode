# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        curr = head
        count = 0
        while curr is not None:
            count += 1
            curr = curr.next
        
        n = ListNode(-1); n.next = head
        i, curr = 1, n
        while i <= count/2+1:
            curr = curr.next
            i += 1
        return curr

