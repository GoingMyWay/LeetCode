# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        res, stack = float('inf'), []
        curr, prev = root, None
        while curr or len(stack):
            while curr:
                stack.append(curr)
                curr = curr.left
            
            curr = stack.pop(-1)
            res = min(abs(curr.val-prev.val) if prev else res, res)
            prev, curr = curr, curr.right
        return res
