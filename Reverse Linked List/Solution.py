# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return head
        
        dummy = ListNode(0)
        dummy.next = head
        
        tmp = dummy.next
        while tmp.next is not None:
            p = tmp.next
            tmp.next = p.next
            p.next = dummy.next
            dummy.next = p
        return dummy.next
