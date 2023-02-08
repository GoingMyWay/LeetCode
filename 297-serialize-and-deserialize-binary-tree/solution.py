# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        self.res = []
        def preorder(root):
            if root is None:
                self.res.append('#')
            else:
                self.res.append(str(root.val))
                preorder(root.left)
                preorder(root.right)
        preorder(root)
        return ','.join(self.res)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        data = data.split(',')
        def build(data):
            if not data: return None

            val = data.pop(0)
            if val == '#': return None
            root = TreeNode(int(val))
            root.left = build(data)
            root.right = build(data)
            return root
        return build(data)

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))