# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def constructFromPrePost(self, preorder, postorder):
        """
        :type preorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """

        index_map = {k: idx for idx, k in enumerate(postorder)}

        def find(preorder,  pre_start,  pre_end,
                 postorder, post_start, post_end):
                
            if pre_start > pre_end: return None
            
            root = TreeNode(preorder[pre_start])
            if pre_start == pre_end: return root

            idx = index_map[preorder[pre_start+1]]
            offset = idx - post_start
            root.left  = find(preorder,  pre_start + 1, pre_start + 1 + offset,
                              postorder, post_start,    idx)
            root.right = find(preorder,  pre_start + 1 + offset + 1, pre_end,
                              postorder, idx + 1,                    post_end)
            return root
        
        return find(preorder, 0, len(preorder)-1, postorder, 0, len(postorder)-1)
