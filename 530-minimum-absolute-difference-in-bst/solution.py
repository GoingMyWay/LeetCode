# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        res, stack = [], []
        curr = root
        min_v = float('inf')
        prev = None
        while (curr or len(stack)):
            while curr:
                stack.append(curr)
                curr = curr.left
            
            curr = stack.pop(-1)
            min_v = min(abs(curr.val-prev.val), min_v) if prev else min_v
            prev = curr
            curr = curr.right
        return min_v
