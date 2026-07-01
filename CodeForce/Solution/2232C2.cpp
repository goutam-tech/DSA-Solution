#include <bits/stdc++.h>
using namespace std;

void seatingArrangement()
{
    long long n, t, s;
    cin >> n >> t >> s;

    string u;
    cin >> u;

    long long l = 0, r = 0, ans = 0;

    for (char c : u)
    {
        if (c == 'I')
        {
            if (l == t)
            {
                continue;
            }
            ans++;
            l++;
            r = min(t, r + 1);
        }
        else if (c == 'E')
        {
            if (ans == r * s)
                continue;
            ans++;
            if (ans > l * s)
                l++;
        }
        else
        {
            if (t * s == ans)
                continue;
            ans++;
            if (ans > l * s)
                l++;
            r = min(t, r + 1);
        }
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
        seatingArrangement();
    return 0;
}