#include <bits/stdc++.h>
using namespace std;

vector<int> line[100000];
int dfn[100000], siz[100000], fa[100000], wp[100000], tp[100000], dep[100000], cdfn;

void dfs1(int t, int f)
{
    vector<int>::iterator it;
    int mx = -1;
    fa[t] = f;
    siz[t] = 1;
    wp[t] = -1;
    for (it = line[t].begin(); it != line[t].end(); it++)
    {
        if ((*it) == f)
            continue;
        dep[*it] = dep[t] + 1;
        dfs1(*it, t);
        siz[t] += siz[*it];
        if (siz[*it] > mx)
        {
            mx = siz[*it];
            wp[t] = *it;
        }
    }
}

void dfs2(int t, int f)
{
    vector<int>::iterator it;
    dfn[t] = cdfn;
    cdfn++;
    if (wp[t] == -1)
        return;
    tp[wp[t]] = tp[t];
    dfs2(wp[t], t);
    for (it = line[t].begin(); it != line[t].end(); it++)
    {
        if ((*it) == f)
            continue;
        if (*it == wp[t])
            continue;
        tp[*it] = *it;
        dfs2(*it, t);
    }
}

map<int, int> mp, sg;

void access(int p)
{
    map<int, int>::iterator it;
    it = sg.upper_bound(p);
    it--;
    sg[p] = it->second;
}

int chkmap(int c, int vl)
{
    map<int, int>::iterator it;
    int d;
    while (1)
    {
        it = mp.upper_bound(vl);
        if (it == mp.begin())
            break;
        it--;
        d = min(it->second, c);
        c -= d;
        it->second -= d;
        if (it->second == 0)
            mp.erase(it);
        if (c == 0)
            break;
    }
    return c;
}

int upd(int l, int r, int p)
{
    int ans = 0, lst, lvl;
    map<int, int>::iterator it;
    access(l);
    access(r);
    lst = l;
    lvl = sg[l];
    while (1)
    {
        it = sg.upper_bound(l);
        ans += chkmap(it->first - lst, lvl);
        lst = it->first;
        lvl = it->second;
        if (it->first == r)
            break;
        sg.erase(it);
    }
    sg[l] = p;
    mp[p] += r - l - ans;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int T, n, m, q, i, u, v, p;
    long long ans;
    for (cin >> T; T > 0; T--)
    {
        cin >> n >> m >> q;
        for (i = 0; i < n - 1; i++)
        {
            cin >> u >> v;
            line[u - 1].push_back(v - 1);
            line[v - 1].push_back(u - 1);
        }
        dep[0] = 0;
        dfs1(0, -1);
        cdfn = 0;
        tp[0] = 0;
        dfs2(0, -1);
        sg[0] = -1;
        sg[n] = -1;
        for (i = 0; i < m; i++)
        {
            cin >> p;
            p--;
            access(dfn[p] + 1);
            sg[dfn[p]] = 0;
        }
        mp[0] = m;
        ans = 0;
        for (i = 1; i <= q; i++)
        {
            u = p;
            cin >> p;
            p--;
            p = (p + ans) % n;
            v = p;
            while (1)
            {
                if (tp[u] == tp[v])
                {
                    if (dep[v] > dep[u])
                        swap(u, v);
                    ans += upd(dfn[v], dfn[u] + 1, i);
                    break;
                }
                if (dep[tp[v]] > dep[tp[u]])
                    swap(u, v);
                ans += upd(dfn[tp[u]], dfn[u] + 1, i);
                u = fa[tp[u]];
            }
            cout << ans << ' ';
        }
        cout << '\n';
        for (i = 0; i < n; i++)
            line[i].clear();
        mp.clear();
        sg.clear();
    }
    return 0;
}