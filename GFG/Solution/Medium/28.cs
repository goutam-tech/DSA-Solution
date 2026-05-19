class Solution {
    public bool canFinish(int n, int[,] prerequisites) {
        // Code Here
        var adj = new List<int>[n];
        for(int i = 0; i < n; i++) adj[i] = new List<int>();
        
        int rows = prerequisites.GetLength(0);
        var inDegree = new int[n];
        
        for(int i = 0; i < rows; i++){
            int x = prerequisites[i,0], y = prerequisites[i,1];
            adj[y].Add(x);
            inDegree[x]++;
        }
        
        var queue = new Queue<int>();
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0) queue.Enqueue(i);
        }
        int count = 0;
        while(queue.Count > 0){
            int node = queue.Dequeue();
            count++;
            foreach(int neighbor in adj[node]){
                if(--inDegree[neighbor] == 0)
                  queue.Enqueue(neighbor);
            }
        }
        
        return count == n;
    }
}