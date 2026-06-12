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
    public TreeNode CreateBinaryTree(int[][] descriptions) {
        Dictionary<int, TreeNode> nodes = new();
        HashSet<int> children = new();

        foreach(int[] d in descriptions){
            int parentVal = d[0], childVal = d[1], isLeft = d[2];

            if(!nodes.ContainsKey(parentVal)) nodes[parentVal] = new TreeNode(parentVal);
            if(!nodes.ContainsKey(childVal)) nodes[childVal] = new TreeNode(childVal);

            if(isLeft == 1) nodes[parentVal].left = nodes[childVal];
            else nodes[parentVal].right = nodes[childVal];

            children.Add(childVal); 
        }

        foreach(var kv in nodes){
            if(!children.Contains(kv.Key)){
                return kv.Value;
            }
        }

        return null;
    }
}