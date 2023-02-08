# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        index_map = {k: idx for idx, k in enumerate(inorder)}
        
        def build(left, right):
            if left >= right:
                return None
            
            root = TreeNode(postorder.pop(-1))
            root.right = build(index_map[root.val]+1, right)
            root.left = build(left, index_map[root.val])
            return root
        
        return build(0, len(inorder))
