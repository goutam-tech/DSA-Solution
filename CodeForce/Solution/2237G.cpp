// #include <bits/stdc++.h>
// using namespace std;
// using i64 = long long;

// constexpr int P = 110;
// constexpr int N = 1000000;
// constexpr int SZV = (1 << 18);

// string type;
// vector<int> ps, pks, v;
// array<int, N + 1> idx;

// void init()
// {
//     vector<int> maxp(N + 1, 0);
//     maxp[1] = 1;
//     for (int i = 2; i <= N; ++i)
//     {
//         if (maxp[i] == 0)
//         {
//             ps.push_back(i);
//             for (int j = i; j <= N; j += i)
//                 maxp[j] = i;
//         }
//     }
//     ps.resize(P);
//     for (int p : ps)
//     {
//         int x = p;
//         while ((i64)x * p <= N)
//             x *= p;
//         pks.push_back(x);
//     }
//     for (int i = 1; i <= N && (int)v.size() < SZV; ++i)
//     {
//         if (maxp[i] <= ps.back())
//             v.push_back(i);
//     }
//     for (int i = 0; i < (int)v.size(); ++i)
//         idx[v[i]] = i;
// }

// void encode()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (int i = 0; i < n; ++i)
//         cin >> a[i];

//     vector<int> b(pks.begin(), pks.end());
//     vector<int> bits;
//     for (int i = 0; i < n; ++i)
//         for (int j = 19; j >= 0; --j)
//             bits.push_back(a[i] >> j & 1);
//     while ((int)bits.size() % 18)
//         bits.push_back(0);

//     for (int i = 0; i < (int)bits.size(); i += 18)
//     {
//         int now = 0;
//         for (int j = 0; j < 18; ++j)
//             now = now * 2 + bits[i + j];
//         b.push_back(v[now]);
//     }

//     int k = (int)b.size();
//     cout << k << '\n';
//     for (int i = 0; i < k; ++i)
//         cout << b[i] << ' ';
//     cout << '\n';
// }

// void decode()
// {
//     int n, k;
//     cin >> n >> k;
//     auto ask = [&](int i, int j)
//     {
//         cout << "? " << i + 1 << ' ' << j + 1 << endl;
//         int g;
//         cin >> g;
//         return g;
//     };

//     vector<int> bits;
//     for (int i = P; i < k; ++i)
//     {
//         int x = 1;
//         for (int j = 0; j < P; ++j)
//             x *= ask(i, j);
//         int now = idx[x];
//         for (int j = 17; j >= 0; --j)
//             bits.push_back(now >> j & 1);
//     }

//     vector<int> a(n);
//     for (int i = 0, j = 0; i < n; ++i, j += 20)
//     {
//         int now = 0;
//         for (int x = 0; x < 20; ++x)
//             now = now * 2 + bits[j + x];
//         a[i] = now;
//     }

//     cout << "!";
//     for (int i = 0; i < n; ++i)
//         cout << ' ' << a[i];
//     cout << endl;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     init();
//     cin >> type;
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         if (type == "first")
//             encode();
//         else
//             decode();
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

long long query(long long i, long long j)
{
    cout << "? " << i << " " << j << '\n'
         << endl;
    long long res;
    cin >> res;
    if (res == -1)
        exit(0);
    return res;
}

void solve_first()
{
    int t;
    if (!(cin >> t))
        return;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int k = n + 1;
        long long base = 1;
        for (int i = 0; i < n; i++)
        {
            base = (base / std::gcd(base, a[i])) * a[i];
        }
        cout << k << endl;
        cout << base;
        for (int i = 0; i < n; i++)
        {
            cout << " " << a[i];
        }
        cout << endl;
    }
}

void solve_second()
{
    int t;
    if (!(cin >> t))
        return;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<long long> ans(n);
        for (int i = 2; i <= k; i++)
        {
            ans[i - 2] = query(1, i);
        }
        cout << "!";
        for (int i = 0; i < n; i++)
        {
            cout << " " << ans[i];
        }
        cout << '\n';
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string stage;
    if (cin >> stage)
    {
        if (stage == "first")
        {
            solve_first();
        }
        else
        {
            solve_second();
        }
    }
    return 0;
}