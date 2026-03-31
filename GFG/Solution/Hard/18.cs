class Solution {
    private int[] disc, low, parent;
    private bool[] visited, ap;
    private List<int>[] adj;
    private int timer;

    public List<int> articulationPoints(int V, List<List<int>> edges) {
        adj = new List<int>[V];
        for (int i = 0; i < V; i++) adj[i] = new List<int>();
        
        foreach (var edge in edges) {
            adj[edge[0]].Add(edge[1]);
            adj[edge[1]].Add(edge[0]);
        }

        disc = new int[V];
        low = new int[V];
        parent = new int[V];
        visited = new bool[V];
        ap = new bool[V];
        
        Array.Fill(parent, -1);
        timer = 0;

        for (int i = 0; i < V; i++){
            if (!visited[i]){
                DFSIterative(i);
            }
        }

        List<int> result = new List<int>();
        for (int i = 0; i < V; i++){
            if (ap[i]) result.Add(i);
        }
        
        if (result.Count == 0) result.Add(-1);
        return result;
    }

    private void DFSIterative(int start) {
        Stack<(int node, int adjIdx)> stack = new Stack<(int, int)>();
        
        visited[start] = true;
        disc[start] = low[start] = timer++;
        stack.Push((start, 0));

        while (stack.Count > 0) {
            var (u, idx) = stack.Peek();
            
            if (idx < adj[u].Count) {
                stack.Pop();
                stack.Push((u, idx + 1));
                
                int v = adj[u][idx];
                
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    disc[v] = low[v] = timer++;
                    stack.Push((v, 0));
                } else if (v != parent[u]) {
                    low[u] = Math.Min(low[u], disc[v]);
                }
            } else {
                stack.Pop();
                
                if (parent[u] != -1) {
                    low[parent[u]] = Math.Min(low[parent[u]], low[u]);
                    
                    if (parent[parent[u]] == -1) {
                        int childCount = 0;
                        foreach (int nb in adj[parent[u]])
                            if (parent[nb] == parent[u]) childCount++;
                        if (childCount > 1) ap[parent[u]] = true;
                    } else {
                        if (low[u] >= disc[parent[u]])
                            ap[parent[u]] = true;
                    }
                }
            }
        }
    }
}