# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        self.tables = {}

        def in_order(root):
            if root is None: return

            in_order(root.left)
            self.tables[root.val] = 1
            in_order(root.right)
        
        in_order(root)
        for _k in self.tables.keys():
            if (k-_k) in self.tables:
                if k-_k != _k:
                    return True
        return False
