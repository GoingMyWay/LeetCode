# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        m_list = set()
        return self.find(root, k, m_list)
    
    def find(self, root, k, m_list):
        if root is None:
            return False
        if k-root.val in m_list:
            return True
        m_list.add(root.val)
        return self.find(root.left, k, m_list) or self.find(root.right, k, m_list)