# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        
        self.rank = 0
        self.res = 0
        def inorder(root):
            
            if root is None: return

            inorder(root.left)
            self.rank += 1
            if (self.rank == k):
                self.res = root.val
                return
            inorder(root.right)
        
        inorder(root)
        return self.res