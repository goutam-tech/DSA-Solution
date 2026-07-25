#include <bits/stdc++.h>
using namespace std;

void cakeTrail()
{
    int n;
    string s;
    cin >> n >> s;
    int NEG = -1000000;
    int SZ = 2 * n + 1;
    vector<vector<int>> dp(SZ, vector<int>(SZ, NEG));
    dp[n][n] = 0;
    for (int i = 0; i < n; i++)
    {
        vector<vector<int>> ndp(SZ, vector<int>(SZ, NEG));
        char c = s[i];
        for (int p = 0; p <= 2 * n; p++)
        {
            int mlo = max(p, n);
            for (int m = mlo; m <= 2 * n; m++)
            {
                if (dp[p][m] == NEG)
                    continue;

                int d = dp[p][m];
                if (c == 'T' || c == 'N')
                {
                    int np = p + 1;
                    if (np <= 2 * n)
                    {
                        int nd = min(d, np - m);
                        int nm = max(m, np);
                        ndp[np][nm] = max(ndp[np][nm], nd);
                    }
                }
                if (c == 'F' || c == 'N')
                {
                    int np = p - 1;
                    if (np >= 0)
                    {
                        int nd = min(d, np - m);
                        int nm = max(m, np);
                        ndp[np][nm] = max(ndp[np][nm], nd);
                    }
                }
            }
        }
        dp = move(ndp);
    }
    int ans = -1000000;
    for (int p = 0; p <= 2 * n; p++)
    {
        int mlo = max(p, n);
        for (int m = mlo; m <= 2 * n; m++)
        {
            if (dp[p][m] == NEG)
                continue;

            int realp = p - n;
            int totalF = (n - realp) / 2;
            ans = max(ans, totalF + dp[p][m]);
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        cakeTrail();
    return 0;
}