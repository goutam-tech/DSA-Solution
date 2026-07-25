#include <bits/stdc++.h>
using namespace std;

const int P = 110;
const int N = 1000000;
const int SZ = 1 << 18;

vector<int> ps, pks, v;
array<int, N + 1> idx_arr;

void init()
{
    vector<int> max_p(N + 1, 0);
    max_p[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        if (max_p[i] == 0)
        {
            ps.push_back(i);
            for (int j = i; j <= N; j += i)
                max_p[j] = i;
        }
    }
    ps.resize(P);
    for (int p : ps)
    {
        long long x = p;
        while (x * p <= N)
            x *= p;
        pks.push_back((int)x);
    }
    for (int i = 1; i <= N && (int)v.size() < SZ; i++)
    {
        if (max_p[i] <= ps.back())
            v.push_back(i);
    }
    for (int i = 0; i < (int)v.size(); i++)
        idx_arr[v[i]] = i;
}

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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> b(pks.begin(), pks.end());
        vector<int> bits;
        for (int i = 0; i < n; i++)
        {
            for (int j = 19; j >= 0; j--)
                bits.push_back((a[i] >> j) & 1);
        }
        while (bits.size() % 18)
            bits.push_back(0);
        for (int i = 0; i < (int)bits.size(); i += 18)
        {
            int now = 0;
            for (int j = 0; j < 18; j++)
                now = now * 2 + bits[i + j];
            b.push_back(v[now]);
        }
        int k = b.size();
        cout << k << '\n';
        for (int i = 0; i < k; i++)
            cout << b[i] << " \n"[i == k - 1];
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
        vector<int> bits;
        for (int i = P; i < k; i++)
        {
            long long x = 1;
            for (int j = 0; j < P; j++)
                x *= query(i + 1, j + 1);
            int now = idx_arr[x];
            for (int j = 17; j >= 0; j--)
                bits.push_back((now >> j) & 1);
        }
        vector<long long> a(n);
        int j = 0;
        for (int i = 0; i < n; i++, j += 20)
        {
            long long now = 0;
            for (int x = 0; x < 20; x++)
                now = now * 2 + bits[j + x];
            a[i] = now;
        }
        cout << "!";
        for (int i = 0; i < n; i++)
            cout << " " << a[i];
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    string stage;
    if (cin >> stage)
    {
        if (stage == "first")
            solve_first();
        else
            solve_second();
    }
    return 0;
}