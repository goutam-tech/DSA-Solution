#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end(),
             [&](int a, int b)
             {
                 return deg[a] > deg[b];
             });
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 1);

    sort(order.begin(), order.end(),
         [&](int a, int b)
         {
             return deg[a] > deg[b];
         });

    int attempts = min(30, n);

    vector<int> best;

    vector<int> used(n + 1);

    for (int startIdx = 0; startIdx < attempts; startIdx++)
    {

        fill(used.begin(), used.end(), 0);

        vector<int> path;
        path.reserve(n);

        int start = order[startIdx];

        path.push_back(start);
        used[start] = 1;

        while (true)
        {
            int u = path.back();

            int nxt = -1;

            for (int v : adj[u])
            {
                if (!used[v])
                {
                    nxt = v;
                    break;
                }
            }

            if (nxt == -1)
                break;

            used[nxt] = 1;
            path.push_back(nxt);
        }

        if ((int)path.size() > (int)best.size())
            best.swap(path);

        if ((int)best.size() == n)
            break;
    }

    cout << best.size() << '\n';

    for (int i = 0; i < (int)best.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << best[i];
    }

    cout << '\n';

    return 0;
}