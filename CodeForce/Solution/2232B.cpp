#include <bits/stdc++.h>
using namespace std;

void cakeLeveling()
{
    int n;
    cin >> n;
    vector<long long> a(n);

    for (auto &x : a)
    {
        cin >> x;
    }

    long long ans = 1e18, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        ans = min(ans, sum / (i + 1));
        cout << ans << " \n"[i == n - 1];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        cakeLeveling();
    return 0;
}