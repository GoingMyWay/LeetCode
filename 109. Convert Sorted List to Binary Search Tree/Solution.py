# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        if head is None or head.next is None:
            return head
        
        vals = []
        curr = head
        while curr != None:
            vals.append(curr.val)
            curr = curr.next
        
        return self.BST(vals)
    
    def BST(self, vals):
        if len(vals) == 0:
            return None
        i = (0+len(vals)) / 2
        node = TreeNode(vals[i])
        node.left = self.BST([] if i==0 else vals[:i])
        node.right = self.BST(vals[i+1:])
        return node
        
        