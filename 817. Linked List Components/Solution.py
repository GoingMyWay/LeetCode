# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def numComponents(self, head, G):
        """
        :type head: ListNode
        :type G: List[int]
        :rtype: int
        """
        p, prev, count, G = head, False, 0, set(G)
        while p:
            if p.val in G and not prev:
                count += 1
            prev, p = p.val in G, p.next;
        
        return count

