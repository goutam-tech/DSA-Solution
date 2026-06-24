#include <bits/stdc++.h>
using namespace std;

void run()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
        if (b[i] != -1)
            b[i]--;
    }
    vector<int> vis(n, 0);
    for (int i = 0; i < n; ++i)
    {
        if (b[i] != -1 && !vis[i])
        {
            int j = i;
            while (!vis[j])
            {
                vis[j] = 1;
                if (b[a[j]] == -1)
                    b[a[j]] = a[b[j]];
                else if (b[a[j]] != a[b[j]])
                {
                    cout << "NO\n";
                    return;
                }
                j = a[j];
            }
        }
    }
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; ++i)
    {
        if (b[i] != -1)
            cnt[b[i]]++;
    }
    for (int i = 0; i < n; ++i)
    {
        if (cnt[i] > 1)
        {
            cout << "NO\n";
            return;
        }
    }

    vector<int> vis1(n, 0), vis2(n, 0);
    vector<vector<int>> cyc1(n + 1), cyc2(n + 1);
    for (int i = 0; i < n; ++i)
    {
        if (b[i] == -1 && !vis1[i])
        {
            int j = i, len = 0;
            while (!vis1[j])
            {
                vis1[j] = 1;
                len++;
                j = a[j];
            }
            cyc1[len].push_back(i);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (cnt[i] == 0 && !vis2[i])
        {
            int j = i, len = 0;
            while (!vis2[j])
            {
                vis2[j] = 1;
                len++;
                j = a[j];
            }
            cyc2[len].push_back(i);
        }
    }

    for (int len = 1; len <= n; ++len)
    {
        for (size_t i = 0; i < cyc1[len].size(); ++i)
        {
            int x = cyc1[len][i], y = cyc2[len][i];
            while (b[x] == -1)
            {
                b[x] = y;
                x = a[x];
                y = a[y];
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i)
    {
        cout << b[i] + 1 << " \n"[i == n - 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        run();
    return 0;
}