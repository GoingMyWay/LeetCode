# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        results = []
        stack = []
        
        while len(stack) != 0 or root is not None:
            if root is not None:
                stack.append(root)
                results.insert(0, root.val)
                root = root.right
            else:
                root = stack.pop()
                root = root.left
        return results
    