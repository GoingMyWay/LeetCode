# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        curr = head
        while curr != None:
            if 'count' not in curr.__dict__:
                curr.count = 1
            else:
                return True
            curr = curr.next
        return False