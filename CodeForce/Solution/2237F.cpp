#include <bits/stdc++.h>
using namespace std;

void paint()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i]--;
    }

    const int inf = 1000000000;
    vector<int> pref(n + 1, -inf), suf(n + 1, -inf), dvpl(n + 1, -inf);
    pref[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        int c = suf[i];
        if (i - a[i] >= 0)
        {
            c = max(c, dvpl[i - a[i]]);
            c = max(c, pref[i - a[i]]);
        }
        c++;
        pref[i + 1] = max(pref[i], c);
        suf[i + 1] = max(suf[i + 1], suf[i]);
        if (i - a[i] >= 0)
        {
            dvpl[i - a[i]] = max(dvpl[i - a[i]], c);
        }
        if (i - a[i] + m <= n)
        {
            suf[i - a[i] + m] = max(suf[i - a[i] + m], c);
        }
    }

    cout << n - max(suf[n], 0) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        paint();
    }
    return 0;
}