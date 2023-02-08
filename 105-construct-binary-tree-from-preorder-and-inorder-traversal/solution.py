# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        index_map = {k: idx for idx, k in enumerate(inorder)}
        
        def build(left, right):
            if left >= right:
                return None
            
            root = TreeNode(preorder.pop(0))
            root.left = build(left, index_map[root.val])
            root.right = build(index_map[root.val]+1, right)
            return root
        
        return build(0, len(inorder))
