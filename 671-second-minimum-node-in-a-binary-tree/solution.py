# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def findSecondMinimumValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if (root.left is None and root.right is None): return -1

        left = root.left.val
        right = root.right.val
        if (root.val == root.left.val):
            left = self.findSecondMinimumValue(root.left)
        if root.val == root.right.val:
            right = self.findSecondMinimumValue(root.right)
        
        if left == -1:
            return right
        
        if right == -1:
            return left
        
        return min(left, right)
