"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: Node
        :rtype: List[List[int]]
        """
        result, queue = [], [root]
        while len(queue) != 0 and root != None:
            qsize = len(queue)
            res = []
            for i in range(qsize):
                n = queue.pop(0)
                res.append(n.val)
                queue += n.children
            result.append(res)
        return result

