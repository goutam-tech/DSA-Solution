// class Node
// {
//     int data;
//     Node left, right;

//     public Node(int d)
//     {
//         data = d;
//         left = right = null;
//     }
// }

class Solution {
    
    private static int maxSize;
    
    // Return the size of the largest sub-tree which is also a BST
    static int largestBst(Node root) {
        // Write your code here
        maxSize = 0;
        dfs(root);
        return maxSize;
    }
    
    private static int[] dfs(Node node){
        if(node == null){
            return new int[]{1,0, Integer.MAX_VALUE, Integer.MIN_VALUE};
        }
        
        int[] left = dfs(node.left);
        int[] right = dfs(node.right);
        
        boolean leftIsBST = left[0] == 1;
        boolean rightIsBST = right[0] == 1;
        int leftMax = left[3];
        int rightMin = right[2];
        
        if(leftIsBST && rightIsBST && leftMax < node.data && node.data < rightMin){
            int size = left[1] + right[1] + 1;
            maxSize = Math.max(maxSize, size);
            int subtreeMin = Math.min(node.data, left[2]);
            int subtreeMax = Math.max(node.data, right[3]);
            return new int[]{1,size, subtreeMin,subtreeMax};
        }
        
        return new int[]{0,0,0,0};
    }
}