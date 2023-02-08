# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.visit(root)    
    
    def visit(self, root):
        if root is None: return 0
        left = self.visit(root.left)
        right = self.visit(root.right)
        return max(left, right) + 1
