public class Solution {
    const int MOD = 1_000_000_007;
    int[] parent, depth;
    int[][] up;
    int n, LOG;

    public int[] AssignEdgeWeights(int[][] edges, int[][] queries) {
        n = edges.Length + 1;
        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        List<int>[] adj = new List<int>[n + 1];
        for (int i = 1; i <= n; i++) adj[i] = new List<int>();
        foreach (var e in edges) {
            adj[e[0]].Add(e[1]);
            adj[e[1]].Add(e[0]);
        }

        parent = new int[n + 1];
        depth = new int[n + 1];
        up = new int[LOG][];
        for (int i = 0; i < LOG; i++){
            up[i] = new int[n + 1];
        }

        bool[] visited = new bool[n + 1];
        Queue<int> queue = new Queue<int>();
        queue.Enqueue(1);
        visited[1] = true;
        parent[1] = 0;
        depth[1] = 0;
        while (queue.Count > 0) {
            int node = queue.Dequeue();
            foreach (int nb in adj[node]) {
                if (!visited[nb]) {
                    visited[nb] = true;
                    parent[nb] = node;
                    depth[nb] = depth[node] + 1;
                    queue.Enqueue(nb);
                }
            }
        }

        for (int v = 1; v <= n; v++){ up[0][v] = parent[v]; }
        for (int k = 1; k < LOG; k++){
            for (int v = 1; v <= n; v++){
                up[k][v] = up[k-1][v] == 0 ? 0 : up[k-1][up[k-1][v]];
            }
        }

        long[] pow2 = new long[n + 1];
        pow2[0] = 1;
        for (int i = 1; i <= n; i++) pow2[i] = pow2[i-1] * 2 % MOD;

        int[] ans = new int[queries.Length];
        for (int i = 0; i < queries.Length; i++) {
            int u = queries[i][0], v = queries[i][1];
            if (u == v) { 
                ans[i] = 0; 
                continue; 
            }
            int lca = LCA(u, v);
            int pathLen = depth[u] + depth[v] - 2 * depth[lca];
            if (pathLen == 0) { 
                ans[i] = 0; 
                continue;
            }
            ans[i] = (int)pow2[pathLen - 1];
        }
        return ans;
    }

    int LCA(int u, int v) {
        if (depth[u] < depth[v]) { int t = u; u = v; v = t; }
        int diff = depth[u] - depth[v];
        for (int k = 0; k < LOG; k++)
            if (((diff >> k) & 1) == 1) u = up[k][u];
        if (u == v) return u;
        for (int k = LOG - 1; k >= 0; k--)
            if (up[k][u] != up[k][v]) { u = up[k][u]; v = up[k][v]; }
        return up[0][u];
    }
}