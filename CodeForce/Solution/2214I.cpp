#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mkp make_pair

const int MOD = 1e9 + 7; // 998244353;

vector<int> adj[200005];
pii dp[200005];
int a[200005];

void dfs(int node, int fa)
{
    if (adj[node].empty())
    {
        dp[node] = mkp(0, 0);
        return;
    }
    dp[node] = mkp(2e9, 2e9);
    for (auto it : adj[node])
    {
        if (it == fa)
            continue;
        dfs(it, node);
        pii cur = dp[it];
        if (a[it] == 1)
            ++cur.f;
        else if (a[it] == 2)
            ++cur.s;
        dp[node] = min(dp[node], cur);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            adj[i].clear();
        }
        for (int i = 2; i <= n; ++i)
        {
            int x;
            cin >> x;
            adj[x].pb(i);
        }
        for (int i = 2; i <= n; ++i)
        {
            cin >> a[i];
        }
        dfs(1, 0);
        int x = 1;
        while (adj[x].size())
        {
            int y = -1;
            for (auto it : adj[x])
            {
                pii cur = dp[it];
                if (a[it] == 1)
                    ++cur.f;
                else if (a[it] == 2)
                    ++cur.s;
                if (cur == dp[x])
                {
                    y = it;
                    break;
                }
            }
            x = y;
        }
        cout << x << '\n';
    }
    return 0;
}