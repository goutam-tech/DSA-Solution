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
public class Solution {
    public TreeNode BalanceBST(TreeNode root) {
        List<int> values = new List<int>();
        Inorder(root,values);
        return BuildBalanceBST(values,0,values.Count-1);
    }

    private void Inorder(TreeNode node, List<int> values){
        if(node == null) return;

        Inorder(node.left,values);
        values.Add(node.val);
        Inorder(node.right,values);
    }

    private TreeNode BuildBalanceBST(List<int> values,int left,int right){
        if(left > right) return null;

        int mid = left + (right - left) / 2;
        TreeNode root = new TreeNode(values[mid]);

        root.left = BuildBalanceBST(values,left,mid-1);
        root.right = BuildBalanceBST(values,mid + 1,right);

        return root;
    }
}