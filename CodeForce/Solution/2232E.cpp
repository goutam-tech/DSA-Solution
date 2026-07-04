#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 200005;

long long fac[MAXN];

void snakingArrangement()
{
    long long n, k;
    cin >> n >> k;

    vector<vector<int>> D;
    vector<int> d;
    bool ok = true;

    for (int i = 0; i < k; i++)
    {
        long long s, r, c;
        cin >> s >> r >> c;

        if (s / 2 + r + c != n + 1)
            ok = false;

        vector<pair<int, int>> V;
        V.push_back({r, c});

        if (s != 1)
        {
            string path;
            cin >> path;
            for (char ch : path)
            {
                if (ch == 'R')
                {
                    c++;
                    V.push_back({r, (int)c});
                }
                else
                {
                    r++;
                    V.push_back({r, (int)c});
                }
            }

            for (int j = 0; j < (int)s / 2; j++)
            {
                if (V[j].second - V[j].first != V[s - j - 1].second - V[s - j - 1].first)
                    ok = false;
            }
        }

        if (!ok)
            continue;

        int depth = s / 2;
        if ((int)D.size() < depth + 1)
        {
            D.resize(depth + 1);
            d.resize(depth + 1, 0);
        }

        for (int j = 0; j <= depth; j++)
            D[j].push_back(V[depth - j].second);
        d[depth] = V[0].second;
    }

    if (!ok)
    {
        cout << "0\n";
        return;
    }

    int x = D.size();
    for (int i = 0; i < x; i++)
        sort(D[i].begin(), D[i].end());
    D.push_back({});

    long long ans = 1;
    for (int i = 0; i < x && ok; i++)
    {
        bool dec = false;
        int l = 0, kk = 0;

        while (l + kk < (int)D[i].size())
        {
            if (D[i][l + kk] == d[i])
            {
                kk++;
                continue;
            }
            if (D[i][l + kk] == D[i + 1][l])
            {
                if (dec)
                {
                    ok = false;
                    break;
                }
            }
            else if (D[i][l + kk] - 1 == D[i + 1][l])
            {
                if (!dec)
                {
                    if (l + kk == 0 && d[i] == 0)
                        ans = ans * (D[i][l + kk] - 1) % MOD;
                    else if (l + kk != 0 && d[i] == 0)
                        ans = ans * (D[i][l + kk] - D[i][l + kk - 1] - 1) % MOD;
                    ans %= MOD;
                }
                dec = true;
            }
            else
            {
                ok = false;
                break;
            }
            l++;
        }

        if (!dec)
        {
            if (d[i] == 0)
            {
                ans = ans * (n - i - (D[i].empty() ? 0 : D[i].back())) % MOD;
                ans %= MOD;
            }
        }
    }

    ans = ans * fac[n - x] % MOD;
    cout << (ok ? ans : 0) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fac[0] = fac[1] = 1;
    for (int i = 2; i < MAXN; i++)
        fac[i] = fac[i - 1] * i % MOD;

    int t;
    cin >> t;
    while (t--)
        snakingArrangement();
    return 0;
}