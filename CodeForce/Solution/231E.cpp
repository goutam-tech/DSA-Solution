#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int LOG = 18;
const int MAXN = 200005;

int n, m;
vector<pair<int, int>> adj[MAXN];
int disc[MAXN], low[MAXN], timer_ = 0;
bool visited[MAXN];

vector<int> tree[MAXN];
bool is_cycle[MAXN];

int dep[MAXN];
int par[MAXN][LOG];
long long cnt[MAXN];

vector<int> stk;

int uf[MAXN];
int find(int x)
{
    while (uf[x] != x)
    {
        uf[x] = uf[uf[x]];
        x = uf[x];
    }
    return x;
}
void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        uf[a] = b;
}

void dfs(int u, int par_edge)
{
    visited[u] = true;
    disc[u] = low[u] = timer_++;
    stk.push_back(u);

    for (auto [v, eid] : adj[u])
    {
        if (eid == par_edge)
            continue;
        if (!visited[v])
        {
            dfs(v, eid);
            low[u] = min(low[u], low[v]);
            if (low[v] >= disc[u])
            {
                vector<int> cyc;
                while (stk.back() != v)
                {
                    cyc.push_back(stk.back());
                    stk.pop_back();
                }
                cyc.push_back(v);
                stk.pop_back();

                if (cyc.size() > 1)
                {
                    for (int x : cyc)
                        unite(x, u);
                    is_cycle[find(u)] = true;
                }
            }
        }
        else if (disc[v] < disc[u])
        {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void bfs_lca(int root)
{
    vector<bool> vis(n + 1, false);
    queue<int> q;
    dep[root] = 0;
    cnt[root] = is_cycle[root] ? 1 : 0;
    for (int j = 0; j < LOG; j++)
        par[root][j] = root;
    vis[root] = true;
    q.push(root);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : tree[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                dep[v] = dep[u] + 1;
                par[v][0] = u;
                cnt[v] = cnt[u] + (is_cycle[v] ? 1 : 0);
                for (int j = 1; j < LOG; j++)
                    par[v][j] = par[par[v][j - 1]][j - 1];
                q.push(v);
            }
        }
    }
}

int lca(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);
    int diff = dep[u] - dep[v];
    for (int j = 0; j < LOG; j++)
        if ((diff >> j) & 1)
            u = par[u][j];
    if (u == v)
        return u;
    for (int j = LOG - 1; j >= 0; j--)
        if (par[u][j] != par[v][j])
        {
            u = par[u][j];
            v = par[v][j];
        }
    return par[u][0];
}

long long pw(long long base, long long exp, long long mod)
{
    long long res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[i] = {a, b};
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }

    for (int i = 1; i <= n; i++)
        uf[i] = i;

    dfs(1, -1);

    for (auto [a, b] : edges)
    {
        int ra = find(a), rb = find(b);
        if (ra != rb)
        {
            tree[ra].push_back(rb);
            tree[rb].push_back(ra);
        }
    }

    int root = find(1);
    bfs_lca(root);

    int k;
    cin >> k;
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        int rx = find(x), ry = find(y);
        int l = lca(rx, ry);
        long long deg = cnt[rx] + cnt[ry] - 2 * cnt[l] + (is_cycle[l] ? 1 : 0);
        cout << pw(2, deg, MOD) << "\n";
    }
}