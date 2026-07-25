/*
 * Complete the 'prims' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY edges
 *  3. INTEGER start
 */

int prims(int n, vector<vector<int>> edges, int start)
{
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto &e : edges)
    {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<bool> visited(n + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    int total = 0;
    int count = 0;

    while (!pq.empty() && count < n)
    {
        auto [w, u] = pq.top();
        pq.pop();

        if (visited[u])
            continue;
        visited[u] = true;
        total += w;
        count++;

        for (auto &[v, wt] : adj[u])
        {
            if (!visited[v])
            {
                pq.push({wt, v});
            }
        }
    }

    return total;
}