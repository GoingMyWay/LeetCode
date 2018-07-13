"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def postorder2(self, root):
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

    def postorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        stack, result = [root], []
        while len(stack) != 0 and root is not None:
            n = stack.pop()
            result.insert(0, n.val)
            stack += n.children
        return result

