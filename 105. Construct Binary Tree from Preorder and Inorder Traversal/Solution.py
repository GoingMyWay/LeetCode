# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if not preorder or not inorder: return None
        root_v = preorder.pop(0)
        root_i = inorder.index(root_v)
        root = TreeNode(root_v)
        root.left = self.buildTree(preorder, inorder[:root_i])
        root.right = self.buildTree(preorder, inorder[root_i+1:])
        return root
