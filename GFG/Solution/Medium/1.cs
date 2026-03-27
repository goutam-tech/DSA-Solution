class Solution {
    public int countPaths(int V, int[,] edges) {
        // code here
        int MOD = 1_000_000_007;
        List<(int, int)>[] adj = new List<(int,int)>[V];
        for(int i = 0; i < V; i++) adj[i] = new List<(int,int)>();
        
        int E = edges.GetLength(0);
        for(int i = 0; i < E; i++){
            int u = edges[i,0], v = edges[i,1], t = edges[i,2];
            adj[u].Add((v,t));
            adj[v].Add((u,t));
        }
        
        long[] dist = new long[V];
        long[] ways = new long[V];
        Array.Fill(dist, long.MaxValue);
        dist[0] = 0;
        ways[0] = 1;
        
        var pq = new PriorityQueue<(long, int),long>();
        pq.Enqueue((0L,0),0L);
        
        
        while(pq.Count > 0){
            var (d,u) = pq.Dequeue();
            if(d > dist[u]) continue;
            foreach(var (v,w) in adj[u]){
                long nd = d + w;
                if(nd < dist[v]){
                    dist[v] = nd;
                    ways[v] = ways[u];
                    pq.Enqueue((nd,v),nd);
                }
                else if(nd == dist[v]){
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return (int)ways[V - 1];
    }
}