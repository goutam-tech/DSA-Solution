class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int MOD = 1e9 + 7;
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int maxDepth = 0;
        queue<pair<int,int>> q;
        q.push({1, 0});
        vector<bool> vis(n + 1, false);
        vis[1] = true;
        while (!q.empty()) {
            auto [node, depth] = q.front(); q.pop();
            maxDepth = max(maxDepth, depth);
            for (int nb : adj[node]) {
                if (!vis[nb]) {
                    vis[nb] = true;
                    q.push({nb, depth + 1});
                }
            }
        }
        if (maxDepth == 0) return 0;
        long long ans = 1;
        for (int i = 0; i < maxDepth - 1; i++) ans = ans * 2 % MOD;
        return ans;
    }
};