# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum_v: int) -> List[List[int]]:
        if root is None:
            return []
        # return self.dfs(root, sum_v)
        result = []
        self.dfs_rec(root, sum_v, [], result)
        return result

    def dfs(self, root: TreeNode, sum_v: int) -> List[List[int]]:
        # DFS + stack
        result, stack = [], [(root, [root.val])]
        while len(stack) != 0:
            node, vals = stack.pop()
            if node.left is None and node.right is None and sum(vals) == sum_v:
                result.append(vals)
            if node.right is not None:
                stack.append((node.right, vals+[node.right.val]))
            if node.left is not None:
                stack.append((node.left, vals+[node.left.val]))
        return result

    def dfs_rec(self, node, sum_v, vals, result):
        if not node.left and not node.right and sum_v == node.val:
            result.append(vals+[node.val])
        if node.left:
            self.dfs_rec(node.left, sum_v-node.val, vals+[node.val], result)
        if node.right:
            self.dfs_rec(node.right, sum_v-node.val, vals+[node.val], result)

    def bfs(self, root: TreeNode, sum_v: int) -> List[List[int]]:
        # BFS + queue
        result, queue = [], [(root, [root.val])]
        while len(queue) != 0:
            node, vals = queue.pop(0)
            if node.left is None and node.right is None and sum(vals) == sum_v:
                result.append(vals[:])
            if node.left is not None:
                queue.append((node.left, vals+[node.left.val]))
            if node.right is not None:
                queue.append((node.right, vals+[node.right.val]))
        return result
