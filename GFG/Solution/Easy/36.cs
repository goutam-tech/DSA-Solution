/* Structure for Tree Node
public class Node {
    public int data;
    public Node left;
    public Node right;

    public Node(int val) {
        data = val;
        left = null;
        right = null;
    }
}
*/
class Solution {
    public void toSumTree(Node root) {
        getSum(root);
    }
    
    private int getSum(Node node) {
        if (node == null) return 0;
        
        int leftSum = getSum(node.left);
        int rightSum = getSum(node.right);
        
        int original = node.data;
        node.data = leftSum + rightSum;
        
        return original + node.data;
    }
}