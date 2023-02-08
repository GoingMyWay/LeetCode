# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        # return self.is_mirror(root.left, root.right)
        return self.iterative(root)
        
    def is_mirror(self, left, right):
        if (left is None and right is None):
            return True
        if (left is None or right is None):
            return False
        return (left.val == right.val) and \
            self.is_mirror(left.left, right.right) and \
                self.is_mirror(left.right, right.left)
    
    def iterative(self, root):
        queue = [root, root]
        while len(queue) != 0:
            left = queue.pop(0)
            right = queue.pop(0)
            if (left is None and right is None):
                continue
            if (left is None or right is None) or (left.val != right.val):
                return False
            
            queue.append(left.left)
            queue.append(right.right)
            queue.append(left.right)
            queue.append(right.left)
        return True
