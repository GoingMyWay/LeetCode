# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        left, right = root, root
        hl, hr = 0, 0
        while left:
            left = left.left
            hl += 1
        
        while right:
            right = right.right
            hr += 1
        
        if hl == hr:
            return 2**hl - 1
        
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)
        # return 1 + self.countNodes(root.right) + self.countNodes(root.left) if root else 0
