#include <bits/stdc++.h>
using namespace std;

void Ghost()
{
    int n;
    cin >> n;
    vector<long long> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    set<pair<long long, int>> avail;
    for (int j = 1; j <= n; j++)
        avail.insert({b[j], j});

    vector<int> perm(n + 1);
    bool ok = true;
    for (int i = 1; i <= n; i++)
    {
        auto it = avail.lower_bound({a[i], 0});
        if (it == avail.end())
        {
            ok = false;
            break;
        }
        perm[i] = it->second;
        avail.erase(it);
    }

    if (!ok)
    {
        cout << -1 << "\n";
        return;
    }

    vector<int> bit(n + 2, 0);
    auto update = [&](int idx)
    {
        for (; idx <= n; idx += idx & (-idx))
            bit[idx]++;
    };

    auto query = [&](int idx)
    {
        int s = 0;
        for (; idx > 0; idx -= idx & (-idx))
            s += bit[idx];
        return s;
    };

    long long inversions = 0;
    for (int i = n; i >= 1; i--)
    {
        inversions += query(perm[i] - 1);
        update(perm[i]);
    }

    cout << inversions << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        Ghost();
    }
    return 0;
}