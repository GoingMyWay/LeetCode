# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def closestValue(self, root: Optional[TreeNode], target: float) -> int:
        self.res = root.val

        def visit(root):
            if root is None:
                return

            if abs(root.val-target) <= abs(self.res-target):
                self.res = root.val
            
            visit(root.left)
            visit(root.right)
        
        visit(root)
        return self.res
