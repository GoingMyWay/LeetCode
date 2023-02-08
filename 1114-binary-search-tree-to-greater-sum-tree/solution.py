# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:

        self.sum = 0

        def inorder(root):
            if root is None: return

            inorder(root.right)
            self.sum += root.val
            root.val = self.sum
            inorder(root.left)
        
        inorder(root)
        return root