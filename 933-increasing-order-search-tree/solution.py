# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def increasingBST(self, root):
        self.res = []
        def inorder(node):
            if node is None: return
            inorder(node.left)
            self.res.append(node.val)
            inorder(node.right)

        ans = cur = TreeNode(None)
        inorder(root)
        for v in self.res:
            cur.right = TreeNode(v)
            cur = cur.right
        return ans.right
