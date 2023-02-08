# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        if n == 0: return []
        
        def build(left, right) -> List[Optional[TreeNode]]:
            res = []
            if left > right:
                res.append(None)
                return res
            
            for i in range(left, right+1):
                left_nodes = build(left, i-1)
                rigth_nodes = build(i+1, right)
                for left_node in left_nodes:
                    for right_node in rigth_nodes:
                        root = TreeNode(i)
                        root.left = left_node
                        root.right = right_node
                        res.append(root)
            return res
        return build(1, n)
