#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<array<int, 3>> ops;

void moveall(int k, int s, int t)
{
    if (k == 0)
        return;
    int u = 6 - s - t;
    if (a[k - 1] == 0)
    {
        moveall(k - 1, s, u);
        ops.push_back({k, s, t});
        moveall(k - 1, u, t);
    }
    else
    {
        moveall(k - 1 - a[k - 1], s, u);
        ops.push_back({k, s, t});
        moveall(k - 1 - a[k - 1], u, s);
        moveall(k - 1, s, t);
    }
}

void magicalCake()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > i)
        {
            ok = false;
            break;
        }
    }

    if (!ok)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    ops.clear();
    moveall(n, 1, 3);
    cout << ops.size() << "\n";
    for (auto &op : ops)
    {
        cout << op[0] << " " << op[1] << " " << op[2] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        magicalCake();
    return 0;
}