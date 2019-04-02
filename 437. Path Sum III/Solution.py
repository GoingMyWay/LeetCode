# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        def dfs(node, sum):
            return dfs(node.left, sum-node.val) + dfs(node.right, sum-node.val) + (sum == node.val) if node else 0
        return dfs(root, sum) + self.pathSum(root.left, sum) + self.pathSum(root.right, sum) if root else 0
