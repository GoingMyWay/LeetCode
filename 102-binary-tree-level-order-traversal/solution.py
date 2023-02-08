# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        results = []
        queue = [root]
        
        while len(queue) != 0 and root is not None:
            results.append([]);
            size = len(queue)
            for _ in range(size):
                node = queue.pop(0)
                results[-1].append(node.val)
                if node.left is not None:
                    queue.append(node.left)
                if node.right is not None:
                    queue.append(node.right)
        return results
