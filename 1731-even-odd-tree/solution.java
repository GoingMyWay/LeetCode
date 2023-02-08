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
    public boolean isEvenOddTree(TreeNode root) {
        if (root == null) {
            return true;
        }

        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        // 记录奇偶层数
        boolean even = true;
        // while 循环控制从上向下一层层遍历
        while (!q.isEmpty()) {
            int sz = q.size();
            // 记录前一个节点，便于判断是否递增/递减
            int prev = even ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            // for 循环控制每一层从左向右遍历
            for (int i = 0; i < sz; i++) {
                TreeNode cur = q.poll();
                if (even) {
                    // 偶数层
                    if (prev >= cur.val || cur.val % 2 == 0) {
                        return false;
                    }
                } else {
                    // 奇数层
                    if (prev <= cur.val || cur.val % 2 == 1) {
                        return false;
                    }
                }
                prev = cur.val;

                if (cur.left != null) {
                    q.offer(cur.left);
                }
                if (cur.right != null) {
                    q.offer(cur.right);
                }
            }
            // 奇偶层数切换
            even = !even;
        }
        return true;
    }
}