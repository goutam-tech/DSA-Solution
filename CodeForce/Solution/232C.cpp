// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// const ll LIMIT = (ll)4e18;
// ll s[1005];

// ll E(int n)
// {
//     if (n < 0)
//         return 0;
//     return (ll)(n + 1) / 2;
// }

// pair<ll, ll> getF(int n, ll x)
// {
//     vector<int> levels, cases;
//     int curN = n;
//     ll curX = x;
//     while (curN >= 2)
//     {
//         levels.push_back(curN);
//         ll left = s[curN - 1];
//         if (curX <= left)
//         {
//             cases.push_back(0);
//             curN = curN - 1;
//         }
//         else
//         {
//             cases.push_back(1);
//             curX = curX - left;
//             curN = curN - 2;
//         }
//     }
//     ll f1, f2;
//     if (curN == 0)
//     {
//         f1 = 0;
//         f2 = 0;
//     }
//     else
//     {
//         if (curX == 1)
//         {
//             f1 = 0;
//             f2 = 1;
//         }
//         else
//         {
//             f1 = 1;
//             f2 = 0;
//         }
//     }

//     for (int i = (int)levels.size() - 1; i >= 0; i--)
//     {
//         int lvln = levels[i];
//         if (cases[i] == 0)
//         {
//             ll newF2 = min(f2, f1) + 1 + E(lvln - 2);
//             f2 = newF2;
//         }
//         else
//         {
//             f1 = 1 + f1;
//         }
//     }

//     return {f1, f2};
// }

// ll distFunc(ll a, ll b, int n)
// {
//     ll x = a, y = b;
//     int curN = n;
//     while (true)
//     {
//         if (curN == 0)
//             return 0;
//         if (curN == 1)
//             return 1;

//         ll left = s[curN - 1];
//         bool xLeft = x <= left, yLeft = y <= left;

//         if (xLeft && yLeft)
//         {
//             curN = curN - 1;
//             continue;
//         }
//         if (!xLeft && !yLeft)
//         {
//             x -= left;
//             y -= left;
//             curN = curN - 2;
//             continue;
//         }
//         ll ax = xLeft ? x : y;
//         ll bx = xLeft ? y : x;
//         auto pa = getF(curN - 1, ax);
//         auto pb = getF(curN - 2, bx - left);

//         return min(pa.second, pa.first) + 1 + pb.first;
//     }
// }

// int t, n;

// void doeGraph()
// {
//     ll a, b;
//     cin >> a >> b;
//     if (a == b)
//     {
//         cout << 0 << '\n';
//     }
//     ll res = distFunc(a, b, n);
//     cout << res << '\n';
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> t >> n;
//     s[0] = 1;
//     if (n >= 1)
//     {
//         s[1] = 2;
//     }

//     for (int i = 2; i <= n; i++)
//     {
//         if (s[i - 1] >= LIMIT || s[i - 2] >= LIMIT)
//         {
//             s[i] = LIMIT;
//         }
//         else
//         {
//             ll sum = s[i - 1] + s[i - 2];
//             s[i] = (sum > LIMIT) ? LIMIT : sum;
//         }
//     }

//     while (t--)
//         doeGraph();

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll LIMIT = (ll)4e18;
ll s[1005];
int n;

void solve()
{
    ll a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << 0 << '\n';
        return;
    }

    vector<int> ba, bb;
    ll x = a, y = b;
    int cn = n;
    while (cn >= 2)
    {
        ll left = s[cn - 1];
        if (x <= left)
        {
            ba.push_back(0);
            cn--;
        }
        else
        {
            ba.push_back(1);
            ba.push_back(0);
            x -= left;
            cn -= 2;
        }
    }
    if (cn == 1)
        ba.push_back(x == 1 ? 0 : 1);

    cn = n;
    while (cn >= 2)
    {
        ll left = s[cn - 1];
        if (y <= left)
        {
            bb.push_back(0);
            cn--;
        }
        else
        {
            bb.push_back(1);
            bb.push_back(0);
            y -= left;
            cn -= 2;
        }
    }
    if (cn == 1)
        bb.push_back(y == 1 ? 0 : 1);

    ll dist = 0;
    for (int i = 0; i < n; i++)
        if (ba[i] != bb[i])
            dist++;

    cout << dist << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t >> n;
    s[0] = 1;
    if (n >= 1)
        s[1] = 2;

    for (int i = 2; i <= n; i++)
    {
        if (s[i - 1] >= LIMIT || s[i - 2] >= LIMIT)
        {
            s[i] = LIMIT;
        }
        else
        {
            ll sum = s[i - 1] + s[i - 2];
            s[i] = (sum > LIMIT) ? LIMIT : sum;
        }
    }

    while (t--)
        solve();

    return 0;
}