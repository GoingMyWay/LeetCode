# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        self.memo = {}
        self.res = []

        def traverse(root):
            if root is None: return "#"

            left = traverse(root.left)
            right = traverse(root.right)

            sub_tree = left + ',' + right + ',' + str(root.val)

            if sub_tree not in self.memo: self.memo[sub_tree] = 0 

            freq = self.memo[sub_tree]
            if freq == 1: self.res.append(root)
            self.memo[sub_tree] += 1

            return sub_tree
        
        traverse(root)
        return self.res
        