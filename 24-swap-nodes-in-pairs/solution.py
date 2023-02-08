# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        return self.reverseKGroup(head, 2)
    
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head: return head
        a, b = head, head
        for i in range(k):
            if not b: return head
            b = b.next
        new_head = self.reverse(a, b)
        a.next = self.reverseKGroup(b, k)
        return new_head
    
    def reverse(self, node_a, node_b):
        pre = None
        cur = node_a
        nxt = node_a
        while cur != node_b:
            nxt = cur.next
            cur.next = pre
            pre = cur
            cur = nxt
        return pre
