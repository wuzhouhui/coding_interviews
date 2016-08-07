import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    public TreeNode(int x) { val = x; }
}

class Solution {
    public List<Integer> zigzag(TreeNode root) {
        List<Integer> res = new LinkedList<>();
        if (root == null)
            return res;
        Stack<TreeNode> s1 = new Stack<>();
        Stack<TreeNode> s2 = new Stack<>();
        boolean dir = true;
        s1.push(root);
        while (!s1.empty()) {
            while (!s1.empty()) {
                TreeNode node = s1.pop();
                if (dir) {
                    if (node.right != null)
                        s2.push(node.right);
                    if (node.left != null)
                        s2.push(node.left);
                } else {
                    if (node.left != null)
                        s2.push(node.left);
                    if (node.right != null)
                        s2.push(node.right);
                }
                res.add(node.val);
            }
            Stack<TreeNode> t = s1;
            s1 = s2;
            s2 = t;
            dir = !dir;
        }
        return res;
    }
}
