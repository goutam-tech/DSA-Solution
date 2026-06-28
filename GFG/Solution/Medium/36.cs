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
    public List<int> topView(Node root) {
        // code here
        List<int> result = new List<int>();
        if(root == null) return result;
        
        SortedDictionary<int,int> map = new SortedDictionary<int,int>();
        Queue<(Node node,int hd)> queue = new Queue<(Node,int)>();
        
        queue.Enqueue((root, 0));
        
        while(queue.Count > 0){
            var (node, hd) = queue.Dequeue();
            
            if(!map.ContainsKey(hd))
              map[hd] = node.data;
              
            if(node.left != null) queue.Enqueue((node.left,hd - 1));
            if(node.right != null) queue.Enqueue((node.right, hd + 1));
        }
        
        foreach(var entry in map){
            result.Add(entry.Value);
        }
        
        return result;
    }
}