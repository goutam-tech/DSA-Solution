#include <bits/stdc++.h>
using namespace std;

const int MOD = 1073741824;
const int MAXN = 1000001;

int d[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i < MAXN; i++)
        for (int j = i; j < MAXN; j += i)
            d[j]++;

    int a, b, c;
    cin >> a >> b >> c;

    int ab = a * b;
    vector<long long> S(ab + 1, 0);

    for (int p = 1; p <= ab; p++)
    {
        for (int k = 1; k <= c; k++)
        {
            S[p] = (S[p] + d[p * k]) % MOD;
        }
    }

    long long ans = 0;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            ans = (ans + S[i * j]) % MOD;
        }
    }

    cout << ans << "\n";
}