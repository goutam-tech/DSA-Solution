#include <bits/stdc++.h>
using namespace std;

void crimsonTriples()
{
    int n;
    cin >> n;
    long long ans = 0;
    for (int b = 1; b <= n; b++)
    {
        ans += 1ll * (n / b) * (n / b);
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        crimsonTriples();
}