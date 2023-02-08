/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder == null || postorder == null || inorder.length != postorder.length) return null;
        HashMap<Integer, Integer> hm = new HashMap<Integer,Integer>();
        for (int i = 0; i < inorder.length; ++i) hm.put(inorder[i], i);
        return buildTreePostIn(0, inorder.length-1, postorder, 0, postorder.length-1,hm);
    }

    private TreeNode buildTreePostIn(int is, int ie, int[] postorder, int ps, int pe, HashMap<Integer,Integer> hm){
        if (ps > pe || is > ie) return null;
        TreeNode root = new TreeNode(postorder[pe]);
        int rV = hm.get(postorder[pe]);
        root.left =  buildTreePostIn(is, rV-1, postorder, ps, ps+rV-is-1, hm);;
        root.right = buildTreePostIn(rV+1, ie, postorder, ps+rV-is, pe-1, hm);;
        return root;
    }
}
