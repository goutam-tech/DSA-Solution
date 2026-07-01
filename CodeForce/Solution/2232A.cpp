#include <bits/stdc++.h>
using namespace std;

void Convergence()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }

    sort(a.begin(), a.end());

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[n - 1 - i])
            cnt++;
    }

    cout << cnt / 2 << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        Convergence();
    return 0;
}