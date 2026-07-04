#include <bits/stdc++.h>
using namespace std;

void magic()
{
    int n, d, l;
    cin >> n >> d >> l;

    int p = (n + 1) / 2, q = n / 2;
    int lo = p - q * l, hi = p * l - q;

    if (d < lo || d > hi)
    {
        cout << -1 << "\n";
        exit(0);
    }

    vector<int> pos(p, 1), neg(q, 1);
    int rem = d - (p - q);

    for (int i = 0; i < p && rem > 0; i++)
    {
        int add = min(rem, l - 1);
        pos[i] += add;
        rem -= add;
    }

    for (int i = 0; i < q && rem < 0; i++)
    {
        int add = min(-rem, l - 1);
        neg[i] += add;
        rem += add;
    }

    int pi = 0, qi = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            cout << pos[pi++];
        }
        else
        {
            cout << neg[qi++];
        }
        if (i < n - 1)
        {
            cout << " ";
        }
    }

    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    magic();

    return 0;
}