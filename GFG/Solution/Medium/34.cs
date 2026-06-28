/*
class Node {
    public int data;
    public Node left, right;

    public Node(int val) {
        data = val;
        left = right = null;
    }
};
*/

class Solution {
    public int countAllPaths(Node root, int k) {
        // code here
        Dictionary<long, int> prefixSums = new Dictionary<long, int>();
        prefixSums[0] = 1;
        return Dfs(root, 0, k, prefixSums);
    }
    
    private int Dfs(Node node, long currentSum, int k, Dictionary<long, int> prefixSums){
        if(node == null) return 0;
        
        currentSum += node.data;
        
        int count = 0;
        if(prefixSums.ContainsKey(currentSum - k))
           count = prefixSums[currentSum - k];
           
        if(prefixSums.ContainsKey(currentSum))
          prefixSums[currentSum]++;
        else
          prefixSums[currentSum] = 1;
          
        count += Dfs(node.left, currentSum, k, prefixSums);
        count += Dfs(node.right, currentSum, k, prefixSums);
        
        prefixSums[currentSum]--;
        
        return count;
    }
}