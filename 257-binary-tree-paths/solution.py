# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        self.results = []
        self.path = []

        def visit(root):
            if root is None:
                return
            
            self.path.append(root)

            if root.left is None and root.right is None:
                self.results.append('->'.join([str(n.val) for n in self.path[:]]))
                self.path.pop(-1)
                return
            
            visit(root.left)
            visit(root.right)
            self.path.pop(-1)

            # for i in range(len(self.path)):
            #     if self.path[i] is root:
            #         self.path = self.path[:i]

        visit(root)
        return self.results
