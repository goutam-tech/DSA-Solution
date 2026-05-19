class Solution {
    public int findMotherVertex(int V, int[][] edges) {
        // code here
        var adj = new List<int>[V];
        for(int i = 0; i < V; i++) adj[i] = new List<int>();
        foreach(var e in edges) adj[e[0]].Add(e[1]);
        
        int[] finishOrder = new int[V];
        bool[] visited = new bool[V];
        int timer = 0;
        
        void DFS(int u){
            visited[u] = true;
            foreach(int w in adj[u]){
                if(!visited[w]) DFS(w);
            }
            finishOrder[timer++] = u;
        }
        
        for(int i = 0; i < V; i++){
            if(!visited[i]) DFS(i);
        }
        
        bool[] reachable = new bool[V];
        void DFS2(int u){
            reachable[u] = true;
            foreach(int w in adj[u]){
                if(!reachable[w]) DFS2(w);
            }
        }
        
        int result = -1;
        for(int i = V - 1; i >= 0; i--){
            int candidate = finishOrder[i];
            Array.Fill(reachable, false);
            DFS2(candidate);
            bool ismother = true;
            for(int j = 0; j < V; j++){
                if(!reachable[j]){
                    ismother = false;
                    break;
                }
            }
            if(ismother){
                if(result == -1 || candidate < result){
                    result = candidate;
                }
            }
        }
        
        return result;
    }
}