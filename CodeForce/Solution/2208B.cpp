#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        long long n, k, p, m;
        cin >> n >> k >> p >> m;
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        long long A = 0;
        if (p > k)
        {
            multiset<long long> opt;
            for (int i = 1; i <= k - 1; i++)
                opt.insert(a[i]);
            for (int i = k; i <= p - 1; i++)
            {
                opt.insert(a[i]);
                A += *opt.begin();
                opt.erase(opt.begin());
            }
        }

        long long rem = m - A - a[p];
        if (rem < 0)
        {
            cout << 0 << "\n";
            continue;
        }

        multiset<long long> all;
        for (int i = 1; i <= n; i++)
            if (i != p)
                all.insert(a[i]);
        long long B = a[p];
        for (int i = 1; i <= n - k; i++)
        {
            B += *all.begin();
            all.erase(all.begin());
        }

        cout << (1 + rem / B) << "\n";
    }
}