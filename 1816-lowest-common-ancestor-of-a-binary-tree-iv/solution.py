# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', nodes: 'List[TreeNode]') -> 'TreeNode':
        node_set = set([n.val for n in nodes])

        def find(root, node_set):
            if root is None: return root

            if root.val in node_set:
                return root
            
            left = find(root.left, node_set)
            right = find(root.right, node_set)

            if left and right: return root

            return left if left else right

        return find(root, node_set)
