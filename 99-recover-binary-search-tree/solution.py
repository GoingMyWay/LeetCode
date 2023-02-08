# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        values = []
        self.inorder(root, values)
        vals = [n.val for n in sorted(values, key=lambda v: v.val)]
        for i in range(len(values)):
            values[i].val = vals[i]

    def inorder(self, root, values):
        if root.left:
            self.inorder(root.left, values)
        values.append(root)
        if root.right:
            self.inorder(root.right, values)
        
        