# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        val1, val2 = min(p.val, q.val), max(p.val, q.val)

        def find(root: 'TreeNode', val1: int, val2: int) -> 'TreeNode':
            if not root: return root

            if (root.val < val1):
                return find(root.right, val1, val2)
            if (root.val > val2):
                return find(root.left, val1, val2)
            
            return root

        return find(root, val1, val2)
