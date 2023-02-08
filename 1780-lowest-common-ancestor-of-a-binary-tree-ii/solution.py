# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.find_left, self.find_right = False, False

        def find(root, p, q):
            if not root: return root

            left = find(root.left, p, q)
            right = find(root.right, p, q)

            # check if both p and q are in the tree
            if left and right: return root

            # check if root is the target p or q
            if root.val == p.val or root.val == q.val:
                if root.val == p.val: self.find_left = True
                if root.val == q.val: self.find_right = True
                return root
            
            return left if left else right
        
        res = find(root, p, q)
        # when both p and q are in the tree, then return res else return None
        return res if (self.find_left and self.find_right) else None
