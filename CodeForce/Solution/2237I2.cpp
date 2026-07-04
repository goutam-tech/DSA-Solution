#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;
vector<int> line[3000];
string s;

long long dp[4][3000][3001], dpc[4][3000][3001], tdp[4][3001], tdpc[4][3001];
int dep[3000], vis1[3000], vislink[3000];

void merge(int u, int v, int pu, int pv, int pt)
{
    int i, j;
    for (i = 0; i <= dep[u]; i++)
    {
        for (j = 0; j <= dep[v]; j++)
        {
            tdp[pt][max(i, j)] = (tdp[pt][max(i, j)] + dp[pu][u][i] * dp[pv][v][j]) % mod;
            if (i <= j)
                tdpc[pt][j] = (tdpc[pt][j] + dp[pu][u][i] * dpc[pv][v][j]) % mod;
            if (i > j)
                tdpc[pt][i] = (tdpc[pt][i] + dpc[pu][u][i] * dp[pv][v][j]) % mod;
        }
    }
}

void dfs(int t)
{
    vector<int>::iterator it;
    int i, j, p, x, y, r0 = 0;
    long long vl;
    dp[0][t][0] = 1;
    dep[t] = 0;
    vis1[t] = 0;
    vislink[t] = 0;
    for (it = line[t].begin(); it != line[t].end(); it++)
    {
        if (s[*it] == '0')
            r0++;
    }
    for (it = line[t].begin(); it != line[t].end(); it++)
    {
        dfs(*it);
        if (s[*it] == '0')
            r0--;
        merge(t, *it, 0, 0, 0);
        if (s[*it] == '1')
        {
            merge(t, *it, 3, 1, 2);
            merge(t, *it, 3, 1, 3);
        }
        else
        {
            merge(t, *it, 2, 1, 2);
            merge(t, *it, 3, 1, 3);
        }
        if (vis1[t] == 0 && r0 == 0 && vislink[*it])
        {
            if (vislink[t] == 0)
            {
                vislink[t] = 1;
                for (i = 0; i <= dep[*it]; i++)
                {
                    tdp[2][i] = (tdp[2][i] + dp[2][*it][i]) % mod;
                    tdpc[2][i] = (tdpc[2][i] + dpc[2][*it][i]) % mod;
                    tdp[3][i] = (tdp[3][i] + dp[3][*it][i]) % mod;
                    tdpc[3][i] = (tdpc[3][i] + dpc[3][*it][i]) % mod;
                }
            }
            else
            {
                for (i = 0; i <= dep[*it]; i++)
                {
                    tdp[2][i] = (tdp[2][i] + dp[2][*it][i]) % mod;
                    tdpc[2][i] = (tdpc[2][i] + dpc[2][*it][i]) % mod;
                    tdp[3][i] = (tdp[3][i] + dp[2][*it][i]) % mod;
                    tdpc[3][i] = (tdpc[3][i] + dpc[2][*it][i]) % mod;
                    if (s[*it] == '1')
                    {
                        tdp[2][i] = (tdp[2][i] + dp[1][*it][i]) % mod;
                        tdpc[2][i] = (tdpc[2][i] + dpc[1][*it][i]) % mod;
                        tdp[3][i] = (tdp[3][i] + dp[1][*it][i]) % mod;
                        tdpc[3][i] = (tdpc[3][i] + dpc[1][*it][i]) % mod;
                    }
                }
            }
        }
        vis1[t] |= vis1[*it];
        dep[t] = max(dep[t], dep[*it]);
        for (p = 0; p < 4; p++)
        {
            for (i = 0; i <= dep[t]; i++)
            {
                dp[p][t][i] = tdp[p][i];
                dpc[p][t][i] = tdpc[p][i];
                tdp[p][i] = 0;
                tdpc[p][i] = 0;
            }
        }
    }
    if (s[t] == '0')
    {
        dep[t]++;
        return;
    }
    for (i = 0; i <= dep[t]; i++)
    {
        tdp[0][i + 1] = (tdp[0][i + 1] + dp[0][t][i]) % mod;
        tdpc[0][i + 1] = (tdpc[0][i + 1] + dpc[0][t][i]) % mod;
    }
    vl = 0;
    for (i = 0; i <= dep[t]; i++)
    {
        vl = (vl + dp[2][t][i]) % mod;
        vl = (vl + mod - dpc[2][t][i]) % mod;
    }
    tdpc[0][1] = (tdpc[0][1] + vl) % mod;
    dep[t]++;
    vislink[t] = 1;
    if (s[t] == '1')
    {
        vis1[t] = 1;
        for (i = 0; i <= dep[t]; i++)
        {
            dp[0][t][i] = tdp[0][i];
            dpc[0][t][i] = tdpc[0][i];
            dp[1][t][i] = tdp[0][i];
            dpc[1][t][i] = tdpc[0][i];
            dp[2][t][i] = 0;
            dpc[2][t][i] = 0;
            dp[3][t][i] = 0;
            dpc[3][t][i] = 0;
        }
    }
    else
    {
        for (i = 0; i <= dep[t]; i++)
        {
            dp[0][t][i] = (dp[0][t][i] + tdp[0][i]) % mod;
            dpc[0][t][i] = (dpc[0][t][i] + tdpc[0][i]) % mod;
            dp[1][t][i] = tdp[0][i];
            dpc[1][t][i] = tdpc[0][i];
            dp[3][t][i] = dp[2][t][i];
            dpc[3][t][i] = dpc[2][t][i];
            dp[2][t][i] = (dp[2][t][i] + tdp[0][i]) % mod;
            dpc[2][t][i] = (dpc[2][t][i] + tdpc[0][i]) % mod;
        }
    }
    for (i = 0; i <= dep[t]; i++)
    {
        tdp[0][i] = 0;
        tdpc[0][i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int T, n, i, j, p, c;
    long long ans;
    for (cin >> T; T > 0; T--)
    {
        cin >> n >> s;
        s = '1' + s;
        for (i = 0; i < n; i++)
        {
            cin >> c;
            for (j = 0; j < c; j++)
            {
                cin >> p;
                line[i].push_back(p - 1);
            }
        }
        for (p = 0; p < 4; p++)
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j <= n; j++)
                {
                    dp[p][i][j] = 0;
                    dpc[p][i][j] = 0;
                }
            }
        }
        dfs(0);
        ans = 0;
        for (i = 0; i <= dep[0]; i++)
        {
            ans = (ans + dp[0][0][i]) % mod;
            ans = (ans + mod - dpc[0][0][i]) % mod;
        }
        cout << ans << '\n';
        for (i = 0; i < n; i++)
            line[i].clear();
    }
    return 0;
}