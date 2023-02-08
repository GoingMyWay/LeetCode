# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        self.sum = 0

        def visit(root, is_left):
            if root is None:
                return
            
            if (root.left is None and root.right is None) and is_left:
                self.sum += root.val
            
            visit(root.left, True)
            visit(root.right, False)
        
        visit(root, False)
        return self.sum
