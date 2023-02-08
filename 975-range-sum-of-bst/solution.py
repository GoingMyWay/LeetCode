# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        self.res = 0
        def in_order_visit(root):
            if root is None: return 

            in_order_visit(root.left)
            if low <= root.val <= high: self.res += root.val
            in_order_visit(root.right)
        
        in_order_visit(root)
        return self.res
