#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5, mod = 998244353;
inline void add(int &x, int v)
{
    x = (x + v) % mod;
}

int T, n, ans, a[N], id[N], mx[N], f[N], sf[N];

void calc(int l, int r)
{
    int tp = 0, cnt = 0;
    f[0] = 1, sf[0] = 1;
    while (true)
    {
        if (mx[l] == 0)
            l++, tp = 0;
        else
            l = mx[l], tp = 1;
        if (l > r)
            break;
        cnt++;
        if (tp == 0)
        {
            for (int i = 1; i <= cnt; i++)
                f[i] = sf[i - 1];
            f[0] = 0;
        }
        else
        {
            for (int i = cnt; i >= 1; i--)
                f[i] = f[i - 1];
            f[0] = 0;
        }
        sf[cnt + 1] = 0;
        for (int i = cnt; i >= 0; i--)
            sf[i] = (sf[i + 1] + f[i]) % mod;
    }
    ans = 1ll * ans * sf[0] % mod;
}
void solve()
{
    cin >> n;
    for (int i = 0; i <= n; i++)
        mx[i] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= i)
        {
            cout << 0 << "\n";
            return;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i] != -1 && a[j] != -1)
            {
                if (a[i] < a[j] && a[j] < i)
                {
                    cout << 0 << "\n";
                    return;
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] != -1)
            id[++cnt] = i;
    sort(id + 1, id + cnt + 1, [](int x, int y)
         { return x - a[x] < y - a[y]; });
    ans = 1;
    for (int i = 1; i <= cnt; i++)
    {
        calc(a[id[i]], id[i] - 1);
        mx[a[id[i]]] = id[i];
    }
    calc(0, n);
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int i = 1; i <= T; i++)
        solve();
}