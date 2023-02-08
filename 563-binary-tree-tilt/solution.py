# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        self.res = 0
    
        def post_order_visit(root):
            if root is None: return 0
            left_v = post_order_visit(root.left)
            right_v = post_order_visit(root.right)
            self.res += abs(left_v - right_v)
            return left_v + right_v + root.val

        post_order_visit(root)
        return self.res
