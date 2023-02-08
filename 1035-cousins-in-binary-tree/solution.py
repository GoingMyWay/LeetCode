# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        queue = []
        if root: queue.append((root, root))

        count_set = set()

        while len(queue):
            size = len(queue)
            for i in range(size):
                node, parent = queue.pop(0)
                if node.val == x:
                    count_set.add(parent)
                elif node.val == y:
                    count_set.add(parent)
                if node.left: queue.append((node.left, node))
                if node.right: queue.append((node.right, node))
            if len(count_set) == 2:
                return True
            elif len(count_set) == 1:
                return False
        return False
        # self.x, self.y = x, y
        # self.p_x, self.p_y = None, None
        # self.depth_x, self.depth_y = 0, 0

        # def traverse(root, depth, parent):
        #     if root is None: return

        #     if root.val == x:
        #         self.p_x = parent
        #         self.depth_x = depth
            
        #     if root.val == y:
        #         self.p_y = parent
        #         self.depth_y = depth
            
        #     traverse(root.left, depth + 1, root)
        #     traverse(root.right, depth + 1, root)
        
        # traverse(root, 0, None)
        # if self.depth_x == self.depth_y and self.p_x != self.p_y:
        #     return True
        # return False