#include <bits/stdc++.h>
using namespace std;

vector<int> zFunction(const string &s)
{
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> z = zFunction(s);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += z[i];
    }
    cout << sum << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}