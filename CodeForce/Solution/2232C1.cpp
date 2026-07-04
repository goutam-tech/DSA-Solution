#include <bits/stdc++.h>
using namespace std;

long long eval(string &s, long long t, long long sz, int m)
{
    long long T = 0, ans = 0;
    for (char c : s)
    {
        if (c == 'I')
        {
            if (T < t)
            {
                T++;
                ans++;
            }
        }
        else if (c == 'E')
        {
            if (ans < T * sz)
                ans++;
        }
        else
        {
            if (m-- > 0)
            {
                if (T < t)
                {
                    T++;
                    ans++;
                }
            }
            else
            {
                if (ans < T * sz)
                    ans++;
            }
        }
    }
    return ans;
}

void seatingArrangement()
{
    long long n, x, s;
    cin >> n >> x >> s;
    string u;
    cin >> u;

    int total_a = count(u.begin(), u.end(), 'A');
    long long ans = 0;
    for (int m = 0; m <= total_a; m++)
    {
        ans = max(ans, eval(u, x, s, m));
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--)
    {
        seatingArrangement();
    }

    return 0;
}