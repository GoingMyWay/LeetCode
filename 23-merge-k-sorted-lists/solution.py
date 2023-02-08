# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        n = len(lists)
        
        while n > 1:
            k = (n + 1) // 2
            for i in range(n//2):
                lists[i] = self._merge_two_linked_list(lists[i], lists[i+k])
            n = k
        return lists[0] if (n != 0) else None
    
    def _merge_two_linked_list(self, l1, l2):
        dummy = ListNode(val=None)
        curr = dummy
        
        while l1 != None and l2 != None:
            if (l1.val < l2.val):
                curr.next = l1
                l1 = l1.next
            else:
                curr.next = l2
                l2 = l2.next
            curr = curr.next
        curr.next = l1 if (l1 != None) else l2
        return dummy.next
