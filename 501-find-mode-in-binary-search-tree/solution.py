# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        self.counter = {}

        def visit(root):
            if root is None:
                return
            
            if root.val not in self.counter:
                self.counter[root.val] = 1
            else:
                self.counter[root.val] += 1
            
            visit(root.left)
            visit(root.right)
        
        visit(root)
        max_count = max(self.counter.values())
        res = [
            k for k, v in self.counter.items() if v == max_count
        ]
        return res
