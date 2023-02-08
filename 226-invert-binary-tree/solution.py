# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
    
        def traverse(root):
            if root is None:
                return
            
            traverse(root.left)

            temp = root.left
            root.left = root.right
            
            traverse(root.right)

            root.right = temp


        traverse(root)
        return root
