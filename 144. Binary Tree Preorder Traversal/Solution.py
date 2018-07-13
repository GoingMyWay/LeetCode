# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = []
        if root != None:
            result.append(root.val)
            result.extend(self.preorderTraversal(root.left))
            result.extend(self.preorderTraversal(root.right))
        return result


class Solution2(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        stack, result = [root], []
        while len(stack) != 0 and root != None:
            n = stack.pop()
            result.append(n.val)
            if n.right != None: stack.append(n.right)
            if n.left != None: stack.append(n.left)
    
        return result

