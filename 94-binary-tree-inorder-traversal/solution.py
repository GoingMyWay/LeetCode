# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res, stack = [], []
        curr = root
        while (curr or len(stack)):
            while curr:
                stack.append(curr)
                curr = curr.left
            
            curr = stack.pop(-1)
            res.append(curr.val)
            curr = curr.right        
        return res
