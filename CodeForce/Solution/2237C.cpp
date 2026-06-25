#include <bits/stdc++.h>
using namespace std;

void DuckSurplus()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<long long> stk;
    for (int i = 0; i < n; i++)
    {
        long long x = a[i];
        while (!stk.empty() && stk.back() > x)
        {
            x += stk.back();
            stk.pop_back();
        }
        stk.push_back(x);
    }

    long long ans = 0;
    for (long long v : stk)
    {
        ans = max(ans, v);
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
    {
        DuckSurplus();
    }
    return 0;
}