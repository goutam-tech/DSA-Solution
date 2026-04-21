/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

namespace Easy;

public class Solution {
    public int SumRootToLeaf(TreeNode root) {
        return DFS(root, 0);
    }

    private int DFS(TreeNode node, int current){
        if(node == null) return 0;
        current = (current << 1) | node.val;
        if(node.left == null && node.right == null) return current;
        return DFS(node.left, current) + DFS(node.right, current);
    }
}