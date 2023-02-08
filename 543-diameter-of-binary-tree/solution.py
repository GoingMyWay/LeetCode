# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.max_depth = 0

        def max_depth(root):
            if root is None:
                return 0
            
            left = max_depth(root.left)
            right = max_depth(root.right)
            self.max_depth = max(self.max_depth, left + right)
            return 1 + max(left, right)
        
        max_depth(root)
        return self.max_depth
