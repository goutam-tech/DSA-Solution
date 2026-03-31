/*
class Node {
    public int data;
    public Node left;
    public Node right;

    public Node(int val) {
        data = val;
        left = right = null;
    }
}
*/

class Solution {
    public static int minTime(Node root, int target) {
        // code here
        Dictionary<Node, Node> parentMap = new Dictionary<Node, Node>();
        Node targetNode = null;
        
        var queue = new Queue<Node>();
        queue.Enqueue(root);
        parentMap[root] = null;
        
        while(queue.Count > 0){
            Node curr = queue.Dequeue();
            if(curr.data == target) targetNode = curr;
            if(curr.left != null){
                parentMap[curr.left] = curr;
                queue.Enqueue(curr.left);
            }
            if(curr.right != null){
                parentMap[curr.right] = curr;
                queue.Enqueue(curr.right);
            }
        }
        
        var visited = new HashSet<Node>();
        var fireQueue = new Queue<Node>();
        fireQueue.Enqueue(targetNode);
        visited.Add(targetNode);
        
        int time = 0;
        
        while(fireQueue.Count > 0){
            int size = fireQueue.Count;
            bool spread = false;
            
            for(int i = 0; i < size; i++){
                Node curr = fireQueue.Dequeue();
                
                if(curr.left != null && !visited.Contains(curr.left)){
                    visited.Add(curr.left);
                    fireQueue.Enqueue(curr.left);
                    spread = true;
                }
                if(curr.right != null && !visited.Contains(curr.right)){
                    visited.Add(curr.right);
                    fireQueue.Enqueue(curr.right);
                    spread = true;
                }
                Node parent = parentMap[curr];
                if(parent != null && !visited.Contains(parent)){
                    visited.Add(parent);
                    fireQueue.Enqueue(parent);
                    spread = true;
                }
            }
            if(spread) time++;
        }
        return time;
    }
}