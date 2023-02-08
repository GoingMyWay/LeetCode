"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        queue = []
        if root:
            queue.append(root)
        curr = None
        while len(queue):
            size = len(queue)
            if size > 0:
                curr = queue.pop(0)
                if curr.left:
                    queue.append(curr.left)
                if curr.right:
                    queue.append(curr.right)

                for i in range(size-1):
                    node = queue.pop(0)
                    curr.next = node
                    curr = node
                    if node.left:
                        queue.append(node.left)
                    if node.right:
                        queue.append(node.right)

        return root