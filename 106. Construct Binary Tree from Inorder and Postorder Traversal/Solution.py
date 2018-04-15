# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if not inorder or not postorder: return None
        root_val = postorder.pop()
        root_val_index = inorder.index(root_val)
        root = TreeNode(root_val)
        root.right = self.buildTree(inorder[root_val_index+1:], postorder)
        root.left = self.buildTree(inorder[:root_val_index], postorder)
        return root

