# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def searchBST2(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        if root is None: return None
        elif root.val == val: return root
        elif root.val > val: return self.searchBST(root.left, val);
        else: return self.searchBST(root.right, val)

    def searchBST(self, root, val):
        stack = [root]
        while len(stack) != 0 and root is not None:
            node = stack.pop()
            if node is None:
                return None
            elif node.val == val: 
                return node
            elif node.val > val: 
                stack.append(node.left)
            else:
                stack.append(node.right)
        return None

