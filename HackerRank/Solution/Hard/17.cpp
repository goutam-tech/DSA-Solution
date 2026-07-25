#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL pw(LL a, LL b, LL p)
{
    LL r = 1;
    a %= p;
    while (b)
    {
        if (b & 1)
            r = r * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return r;
}

vector<long> pseudoIsomorphicSubstrings(string s)
{
    int N = s.size();
    if (!N)
        return {};

    const char *cc = s.c_str();

    vector<vector<int>> perm(26, vector<int>(N + 1));
    vector<int> llast(26);
    map<int, int> ml;
    for (int i = 0; i < 26; i++)
    {
        llast[i] = 1000000 + i;
        ml[llast[i]] = i;
    }
    for (int i = N - 1; i >= 0; i--)
    {
        int tmp = cc[i] - 'a', ctr = 1;
        ml.erase(llast[tmp]);
        llast[tmp] = i;
        ml[i] = tmp;
        for (auto &pr : ml)
            perm[pr.second][i] = ctr++;
    }

    vector<int> v(N, 1000000);
    const LL mod1 = 1000000007, factor1 = 37;
    vector<LL> factors1(N + 2);
    factors1[0] = 1;
    LL inv1 = pw(factor1, mod1 - 2, mod1);
    for (int i = 1; i < (int)factors1.size(); i++)
        factors1[i] = factors1[i - 1] * factor1 % mod1;

    map<pair<int, LL>, int> hs;
    hs[{0, 0}] = 0;
    hs[{1, 1}] = 0;

    v[0] = 1;
    int currlen = 1, actsimilar = 0;
    vector<LL> w1(26, 0);
    if (N > 1)
        w1[cc[1] - 'a']++;

    for (int st = 1; st < N; st++)
    {
        LL currhash = 0;
        for (int i = 0; i < 26; i++)
        {
            currhash += w1[i] * perm[i][st];
            currhash %= mod1;
        }

        while (hs.count({currlen, currhash}))
        {
            actsimilar = hs[{currlen, currhash}];
            for (++currlen; st + currlen <= N; ++currlen)
            {
                w1[cc[st + currlen - 1] - 'a'] += factors1[currlen - 1];
                if (w1[cc[st + currlen - 1] - 'a'] >= mod1)
                    w1[cc[st + currlen - 1] - 'a'] -= mod1;
                currhash += factors1[currlen - 1] * perm[cc[st + currlen - 1] - 'a'][st];
                currhash %= mod1;
                if (perm[cc[actsimilar + currlen - 1] - 'a'][actsimilar] !=
                    perm[cc[st + currlen - 1] - 'a'][st])
                    break;
            }
        }

        if (currlen + st > N)
            break;

        hs[{currlen, currhash}] = st;
        currhash += (mod1 - factors1[currlen - 1]) * perm[cc[st + currlen - 1] - 'a'][st];
        currhash %= mod1;
        currhash += factors1[currlen - 1] * perm[cc[actsimilar + currlen - 1] - 'a'][actsimilar];
        currhash %= mod1;
        if (!hs.count({currlen, currhash}))
            hs[{currlen, currhash}] = actsimilar;

        v[st] = currlen;
        w1[cc[st] - 'a']--;
        if (w1[cc[st] - 'a'] < 0)
            w1[cc[st] - 'a'] += mod1;
        --currlen;

        if (currlen > 1)
        {
            w1[cc[st + currlen] - 'a'] -= factors1[currlen];
            if (w1[cc[st + currlen] - 'a'] < 0)
                w1[cc[st + currlen] - 'a'] += mod1;
            --currlen;
        }

        currhash = 0;
        for (int i = 0; i < 26; i++)
        {
            w1[i] = w1[i] * inv1 % mod1;
            currhash += w1[i] * perm[i][st + 1];
            currhash %= mod1;
        }
        if (currlen > 1 && !hs.count({currlen, currhash}))
            hs[{currlen, currhash}] = actsimilar + 1;
    }

    vector<LL> vz(N, 0), vv(N, 0);
    for (int i = 0; i < N; i++)
        if (i + v[i] <= N)
            vz[i + v[i] - 1]++;
    vv[0] = vz[0];
    for (int i = 1; i < N; i++)
    {
        vz[i] += vz[i - 1];
        vv[i] = vv[i - 1] + vz[i];
    }

    vector<long> res(N);
    for (int i = 0; i < N; i++)
        res[i] = (long)vv[i];
    return res;
}

int main()
{
    string s;
    cin >> s;

    vector<long> result = pseudoIsomorphicSubstrings(s);

    for (long x : result)
        cout << x << "\n";

    return 0;
}