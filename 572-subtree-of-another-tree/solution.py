# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if root is None:
            return subRoot is None
        if self.check_substree(root, subRoot):
            return True
        return self.isSubtree(root.left, subRoot) or \
            self.isSubtree(root.right, subRoot)

    def check_substree(self, root, subRoot):
        if root is None and subRoot is None:
            return True
        if root is None or subRoot is None:
            return False
        if root.val != subRoot.val:
            return False

        return self.check_substree(root.left, subRoot.left) and \
            self.check_substree(root.right, subRoot.right)