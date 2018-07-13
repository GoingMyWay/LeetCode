"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def postorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        result = []
        if root is not None:
            vec = []
            for child in root.children:
                vec.extend(self.postorder(child))
            result.extend(vec)
            result.append(root.val)
        return result

