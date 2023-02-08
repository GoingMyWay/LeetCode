# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        # results = []
        # stack = [root]
        # while root is not None and len(stack) != 0:
        #     node = stack.pop()
        #     results.append(node.val)
        #     if node.right is not None:
        #         stack.append(node.right)
        #     if node.left is not None: 
        #         stack.append(node.left)
        # return results
        result = []
        if root != None:
            result.append(root.val)
            result.extend(self.preorderTraversal(root.left))
            result.extend(self.preorderTraversal(root.right))
        return result
    
