/*
class Node {
    public int data;
    public Node left;
    public Node right;

    public Node(int key) {
        this.data = key;
        this.left = null;
        this.right = null;
    }
}
*/

class Solution {
    public int distCandy(Node root) {
       int totalMoves = 0;
       DFS(root, ref totalMoves);
       return totalMoves;
        
    }
    
    private int DFS(Node node, ref int totalMoves){
        if(node == null) return 0;
        int left = DFS(node.left, ref totalMoves);
        int right = DFS(node.right, ref totalMoves);
        int excess = node.data + left + right - 1;
        totalMoves += Math.Abs(excess);
        return excess;
    }
}