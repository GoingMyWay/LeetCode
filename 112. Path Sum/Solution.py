# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if node is None:
            return False
        if node.val == sum and node.left is None and node.right is None:
            return True
        return self.hasPathSum(node.left, sum-node.val) or self.hasPathSum(node.right, sum-node.val)


# if __name__ == '__main__':
#     node = TreeNode(5)
#     n1 = TreeNode(4)
#     n2 = TreeNode(8)
#     node.left, node.right = n1, n2
#     n3 = TreeNode(11)
#     n4 = TreeNode(13)
#     n1.left = n3
#     n5 = TreeNode(4)
#     n2.left, n2.right = n4, n5
#     n6 = TreeNode(7)
#     n7 = TreeNode(2)
#     n8 = TreeNode(1)
#     n3.left, n3.right = n6, n7
#     n5.right = n8
#     s = Solution()
#     res = s.hasPathSum(node, 22)
