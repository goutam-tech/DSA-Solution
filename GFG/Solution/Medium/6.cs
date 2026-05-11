/*
Definition for Node
class Node {
    public int data;
    public Node left, right;

    public Node(int val) {
        data = val;
        left = right = null;
    }
}
*/
class Solution {
    public bool isSubTree(Node root1, Node root2) {
        if (root2 == null) return true;
        if (root1 == null) return false;
        if (isIdentical(root1, root2)) return true;
        return isSubTree(root1.left, root2) || isSubTree(root1.right, root2);
    }
    
    private bool isIdentical(Node a, Node b) {
        if (a == null && b == null) return true;
        if (a == null || b == null) return false;
        if (a.data != b.data) return false;
        return isIdentical(a.left, b.left) && isIdentical(a.right, b.right);
    }
}