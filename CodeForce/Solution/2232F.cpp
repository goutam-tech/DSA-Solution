#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void cakeIsLie()
{
    ll n, a, b, k;
    cin >> n >> a >> b >> k;

    ll g = __gcd(a, b);

    if (k % g != 0)
    {
        cout << "0\n";
        return;
    }

    a /= g;
    b /= g;
    k /= g;

    if (a == 1 && b == 1)
    {
        cout << n << "\n";
        return;
    }

    ll ans = 0;
    ll x = 0;
    if (k % a == 0)
    {
        ans++;
        n--;
        x = k / a;
        while (n > 0)
        {
            if (k - x * b < 0 || (k - x * b) % a != 0)
            {
                break;
            }
            x = (k - x * b) / a;
            ans++;
            n--;
        }
    }

    ll v = 0;
    if (k % (a + b) == 0)
    {
        v = 1e9;
    }
    else
    {
        if (a < b)
        {
            swap(a, b);
        }
        ll m = b;

        while (true)
        {
            ll px, py;
            gcd(a + b, m, px, py);

            if (px < 0)
            {
                px += m;
                py -= (a + b);
            }

            px *= k;
            py *= k;

            ll dd = px / m;
            px -= dd * m;
            py += dd * (a + b);

            if (m / b * py + px < 0)
                break;

            bool valid = true;
            ll x1 = px, x2 = m / b * py + px;
            for (int _ = 0; _ < v; _++)
            {
                if (a * x1 + b * x2 != k)
                {
                    valid = false;
                }
                if ((k - b * x1) % a)
                {
                    valid = false;
                    break;
                }
                x2 = x1;
                x1 = (k - b * x1) / a;
            }

            if (!valid)
                break;

            v++;

            if (a > k / m)
                break;

            m *= a;
        }
    }

    cout << ans + (n - (n + v) / (v + 1)) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        cakeIsLie();
    return 0;
}