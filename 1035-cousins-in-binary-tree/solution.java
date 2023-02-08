/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    TreeNode parentX = null, parentY = null;
    int depthX = 0, depthY = 0;
    int x, y;
    public boolean isCousins(TreeNode root, int x, int y) {
        this.x = x;
        this.y = y;
        traverse(root, 0, null);
        if (depthX == depthY && parentX != parentY) return true;
        return false;
    }

    public void traverse(TreeNode root, int depth, TreeNode parent) {
        if (root == null) return;
        if (root.val == x) {
            parentX = parent;
            depthX = depth;
        }
        if (root.val == y) {
            parentY = parent;
            depthY = depth;
        }
        traverse(root.left,  depth + 1, root);
        traverse(root.right, depth + 1, root);
    }
}