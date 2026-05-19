class Solution {
    public List<int> minHeightRoot(int V, int[,] edges) {
        // Code here
        if(V == 1) return new List<int> ( 0 );
        
        List<int>[] adj = new List<int>[V];
        for(int i = 0; i < V; i++) adj[i] = new List<int>();
        
        int E = edges.GetLength(0);
        for(int i = 0; i < E; i++){
            int u = edges[i,0], v = edges[i,1];
            adj[u].Add(v);
            adj[v].Add(u);
        }
        
        int[] degree = new int[V];
        for(int i = 0; i < V; i++) degree[i] = adj[i].Count;
        
        var leaves = new Queue<int>();
        for(int i = 0; i < V; i++){
            if(degree[i] == 1) leaves.Enqueue(i);
        }
        
        int remaining = V;
        while(remaining > 2){
            int leftCount = leaves.Count;
            remaining -= leftCount;
            for(int i = 0; i < leftCount; i++){
                int left = leaves.Dequeue();
                foreach(int nb in adj[left]){
                    degree[nb]--;
                    if(degree[nb] == 1) leaves.Enqueue(nb);
                }
            }
        }
        
        return new List<int>(leaves);
    }
}
