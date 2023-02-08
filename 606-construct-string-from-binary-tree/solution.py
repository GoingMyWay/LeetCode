# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:

        self.res = ""

        def visit(root, is_left, other_child):
            
            if root is None:
                if is_left and other_child:
                    self.res += "()"
                return
            
            self.res += f"({root.val}"
            visit(root.left, True, root.right)
            visit(root.right, False, root.left)
            self.res += ")"
        
        visit(root, False, None)
        return self.res[1:-1]
