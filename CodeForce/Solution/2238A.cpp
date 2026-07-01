#include <bits/stdc++.h>
using namespace std;

void Papyrus()
{
    int n, c;
    cin >> n >> c;
    vector<long long> a(n), b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;

    long long without_reorder = 0;
    bool can = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < b[i])
        {
            can = false;
            break;
        }
        without_reorder += a[i] - b[i];
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    bool can2 = true;
    long long with_reorder = c;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < b[i])
        {
            can2 = false;
            break;
        }
        with_reorder += a[i] - b[i];
    }

    if (!can && !can2)
        cout << -1 << "\n";
    else if (!can)
        cout << with_reorder << "\n";
    else if (!can2)
        cout << without_reorder << "\n";
    else
        cout << min(without_reorder, with_reorder) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        Papyrus();
}