#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, k, t;
    cin >> n >> k >> t;

    long long total = t * n * k / 100;

    for (int i = 0; i < n; i++)
    {
        long long val = min(total, k);
        cout << val;
        if (i < n - 1)
            cout << " ";
        total -= val;
    }

    cout << "\n";
}