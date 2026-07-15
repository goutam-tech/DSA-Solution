class Solution
{
public:
    int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online, long long k)
    {
        int n = online.size();
        vector<vector<pair<int, long long>>> adj(n);
        vector<int> indeg(n, 0);
        vector<long long> costs;
        for (auto &e : edges)
        {
            int u = e[0], v = e[1];
            long long c = e[2];
            adj[u].push_back({v, c});
            indeg[v]++;
            costs.push_back(c);
        }
        vector<int> topo;
        topo.reserve(n);
        queue<int> q;
        vector<int> indeg2 = indeg;
        for (int i = 0; i < n; i++)
            if (indeg2[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (auto &pr : adj[u])
            {
                if (--indeg2[pr.first] == 0)
                    q.push(pr.first);
            }
        }
        if (costs.empty())
            return -1;
        sort(costs.begin(), costs.end());
        costs.erase(unique(costs.begin(), costs.end()), costs.end());
        const long long INF = LLONG_MAX / 2;
        auto feasible = [&](long long T) -> bool
        {
            vector<long long> dist(n, INF);
            dist[0] = 0;
            for (int u : topo)
            {
                if (dist[u] >= INF)
                    continue;
                for (auto &pr : adj[u])
                {
                    int v = pr.first;
                    long long c = pr.second;
                    if (c < T)
                        continue;
                    if (!online[u] || !online[v])
                        continue;
                    long long nd = dist[u] + c;
                    if (nd < dist[v])
                        dist[v] = nd;
                }
            }
            return dist[n - 1] <= k;
        };
        int lo = 0, hi = (int)costs.size() - 1, ans = -1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (feasible(costs[mid]))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        if (ans == -1)
            return -1;
        return (int)costs[ans];
    }
};