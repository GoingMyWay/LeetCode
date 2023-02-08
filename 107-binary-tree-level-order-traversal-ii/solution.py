# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        res, queue = [], []
        if root: queue.append(root)
        while len(queue):
            size = len(queue)
            res.append([])
            for i in range(size):
                node = queue.pop(0)
                res[-1].append(node.val)
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)
        return res[::-1]
