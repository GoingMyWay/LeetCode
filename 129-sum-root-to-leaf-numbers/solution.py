# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        # return self.dfs(root, 0)
        return self.iterative(root)
    
    # def dfs(self, root: Optional[TreeNode], sum_v: int) -> int:
    #     if root is None:
    #         return 0
    #     sum_v = sum_v * 10 + root.val
    #     if (root.left is None and root.right is None):
    #         return sum_v
    #     return self.dfs(root.left, sum_v) + self.dfs(root.right, sum_v)

    def iterative(self, root):
        res = 0
        stack = [root]
        while len(stack) != 0:
            node = stack.pop()
            if node.left is None and node.right is None:
                res += node.val
            
            if node.left is not None:
                node.left.val += node.val * 10
                stack.append(node.left)
            
            if node.right is not None:
                node.right.val += node.val * 10
                stack.append(node.right)
        return res
