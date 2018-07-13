"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def preorder2(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        result = []
        self._visit(result, root)
        return result
    
    def _visit(self, result, root):
        if root is not None:
            result.append(root.val)
            for ch in root.children:
                self._visit(result, ch)
    
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        result, res = [], []
        if root is not None:
            res.append(root.val)
            for child in root.children: 
                vec = self.preorder(child)
                res.extend(vec)
            result.extend(res)
        return result

