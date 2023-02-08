# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:


        def build(preorder, left, right):
            if left > right: return None

            root =  TreeNode(preorder[left])

            p = left + 1
            while p <= right and preorder[p] < root.val:
                p += 1
            
            root.left  = build(preorder, left + 1, p - 1)
            root.right = build(preorder, p, right)
            return root

        return build(preorder, 0, len(preorder)-1) 