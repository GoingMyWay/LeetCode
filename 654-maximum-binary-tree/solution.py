# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        def build(nums):
            if len(nums) == 0: return None
            
            max_v = max(nums)
            max_i = -1
            for i, v in enumerate(nums):
                if v == max_v:
                    max_i = i
                    break

            node = TreeNode(val=max_v)
            node.left = build(nums[:max_i])
            node.right = build(nums[max_i+1:])
            return node

        return build(nums)