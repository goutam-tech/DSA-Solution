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
        int n;
        cin >> n;
        long long mn = 1001, sum = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            mn = min(mn, (long long)a);
            sum += mn;
        }
        cout << sum << '\n';
    }
    return 0;
}