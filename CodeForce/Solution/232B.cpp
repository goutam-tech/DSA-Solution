#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

long long modpow(long long base, long long exp, long long mod)
{
    base %= mod;
    if (base < 0)
        base += mod;

    long long result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }

    return result;
}

vector<long long> multiply(const vector<long long> &a, const vector<long long> &b, int maxDeg)
{
    vector<long long> c(min((int)(a.size() + b.size() - 2), maxDeg) + 1, 0);
    for (int i = 0; i < (int)a.size(); i++)
    {
        if (a[i] == 0)
            continue;
        for (int j = 0; j < (int)b.size(); j++)
        {
            if (i + j > maxDeg)
                break;
            c[i + j] = (c[i + j] + a[i] * b[j]) % MOD;
        }
    }
    return c;
}

void table()
{
    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> C(n + 1, 0);
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        vector<long long> newC(n + 1, 0);
        newC[0] = 1;
        for (int j = 1; j <= i; j++)
        {
            newC[j] = (C[j] + (j > 0 ? C[j - 1] : 0)) % MOD;
        }
        C = newC;
    }

    long long q = m / n;
    long long r = m % n;

    vector<long long> P0(n + 1), P1(n + 1);
    for (int v = 0; v <= n; v++)
    {
        P0[v] = modpow(C[v], q, MOD);
        P1[v] = (P0[v] * (C[v] % MOD)) % MOD;
    }

    int maxDeg = (int)(n * n);
    vector<long long> poly(1, 1);

    for (long long i = 0; i < r; i++)
    {
        poly = multiply(poly, P1, maxDeg);
    }
    for (long long i = 0; i < n - r; i++)
    {
        poly = multiply(poly, P0, maxDeg);
    }

    long long ans = (k < (long long)poly.size()) ? poly[k] : 0;
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    table();

    return 0;
}