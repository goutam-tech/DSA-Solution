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
    public List<List<int>> verticalOrder(Node root) {
        // code here
        var result = new List<List<int>>();
        
        var columnMap = new SortedDictionary<int, List<int>>();
        var queue = new Queue<(Node node, int col)>();
        queue.Enqueue((root,0));
        
        while(queue.Count > 0){
            var (node, col) = queue.Dequeue();
            
            if(!columnMap.ContainsKey(col))
              columnMap[col] = new List<int>();
              
            columnMap[col].Add(node.data);
            
            if(node.left != null) queue.Enqueue((node.left, col - 1));
            if(node.right != null) queue.Enqueue((node.right, col + 1));
        }
        
        foreach(var entry in columnMap){
            result.Add(entry.Value);
        }
        
        return result;
    }
}