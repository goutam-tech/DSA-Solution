#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> t(n);

    for (int i = 0; i < n; i++)
        cin >> t[i];

    long long ans = LLONG_MIN;

    for (int k = 3; k <= n; k++)
    {
        if (n % k != 0)
            continue;
        int step = n / k;
        for (int start = 0; start < step; start++)
        {
            long long sum = 0;
            for (int j = start; j < n; j += step)
                sum += t[j];
            ans = max(ans, sum);
        }
    }
    cout << ans << "\n";
}