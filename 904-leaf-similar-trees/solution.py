# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        res1, res2 = [], []
        self.traverse(root1, res1)
        self.traverse(root2, res2)
        return all(v1==v2 for v1, v2 in itertools.izip_longest(res1, res2))
    
    def traverse(self, root, res):
        if root.left is None and root.right is None:
            res.append(root.val)
        else:
            if root.left is not None:
                self.traverse(root.left, res)
            if root.right is not None:
                self.traverse(root.right, res)
