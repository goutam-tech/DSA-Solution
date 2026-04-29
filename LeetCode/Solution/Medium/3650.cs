public class Solution {
    public int MinCost(int n, int[][] edges) {
        var graph = new List<(int to, int cost)>[n]; 
        for (int i = 0; i < n; i++) 
            graph[i] = new List<(int, int)>();

        foreach (var e in edges) { 
            int u = e[0], v = e[1], w = e[2]; 
            graph[u].Add((v, w));  
            graph[v].Add((u, 2 * w)); 
        }

        var dist = new int[n]; 
        Array.Fill(dist, int.MaxValue); 
        dist[0] = 0; 

        var pq = new PriorityQueue<(int node, int cost), int>(); 
        pq.Enqueue((0, 0), 0);
        
        while (pq.Count > 0) { 
            pq.TryDequeue(out var item, out int currCost); 
            int u = item.node; 
            if (u == n - 1) return currCost;  
            if (currCost > dist[u]) continue; 
            foreach (var (v, w) in graph[u]) { 
                int newCost = currCost + w; 
                if (newCost < dist[v]) { 
                    dist[v] = newCost; 
                    pq.Enqueue((v, newCost), newCost); 
                } 
            } 
        }
        // return dist[n - 1] == int.MaxValue ? -1 : dist[n - 1];
        return -1;
    }
}