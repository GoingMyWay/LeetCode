# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        self._target = target
        self.res = None

        def traverse(original, cloned):
            if original is None or self.res is not None:
                return
            
            if original == target:
                self.res = cloned
                return
            
            traverse(original.left,  cloned.left)
            traverse(original.right, cloned.right)
        
        traverse(original, cloned)
        return self.res
