/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public List<Integer> postorder(Node root) {
        List<Integer> result = new LinkedList<>();
        Stack<Node> stack = new Stack<>(); stack.push(root);
        while (!stack.empty() && root != null) {
            Node node = stack.pop();
            result.add(0, node.val);
            for (Node n : node.children) stack.push(n);
        }
        return result;
    }

    public List<Integer> postorder2(Node root) {
        List<Integer> result = new LinkedList<>();
        if (root != null) {
            List<Integer> res = new LinkedList<>();
            for (Node n : root.children) res.addAll(postorder(n));
            result.addAll(res);
            result.add(root.val);
        }
        return result;
    }
}
