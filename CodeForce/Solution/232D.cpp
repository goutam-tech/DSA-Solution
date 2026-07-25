#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m;
vector<ll> A;
vector<int> sa, rnk, tmp;
vector<int> lcp;
vector<vector<int>> sparse;
vector<int> logt;

void buildSA()
{
    sa.resize(m);
    rnk.resize(m);
    tmp.resize(m);
    iota(sa.begin(), sa.end(), 0);
    vector<ll> srt(A);
    sort(srt.begin(), srt.end());
    srt.erase(unique(srt.begin(), srt.end()), srt.end());
    for (int i = 0; i < m; i++)
        rnk[i] = (int)(lower_bound(srt.begin(), srt.end(), A[i]) - srt.begin());
    for (int k = 1; k < m; k <<= 1)
    {
        auto cmp = [&](int a, int b)
        {
            if (rnk[a] != rnk[b])
                return rnk[a] < rnk[b];
            int ra = a + k < m ? rnk[a + k] : -1;
            int rb = b + k < m ? rnk[b + k] : -1;
            return ra < rb;
        };
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < m; i++)
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        rnk = tmp;
        if (rnk[sa[m - 1]] == m - 1)
            break;
    }
}

void buildLCP()
{
    lcp.assign(m, 0);
    int h = 0;
    for (int i = 0; i < m; i++)
    {
        if (rnk[i] > 0)
        {
            int j = sa[rnk[i] - 1];
            while (i + h < m && j + h < m && A[i + h] == A[j + h])
                h++;
            lcp[rnk[i]] = h;
            if (h > 0)
                h--;
        }
        else
            h = 0;
    }
}

void buildSparse()
{
    logt.assign(m + 1, 0);
    for (int i = 2; i <= m; i++)
        logt[i] = logt[i / 2] + 1;
    int K = logt[m] + 1;
    sparse.assign(K, vector<int>(m, INT_MAX));
    for (int i = 1; i < m; i++)
        sparse[0][i] = lcp[i];
    for (int k = 1; k < K; k++)
    {
        for (int i = 1; i + (1 << k) <= m; i++)
        {
            sparse[k][i] = min(sparse[k - 1][i], sparse[k - 1][i + (1 << (k - 1))]);
        }
    }
}

int rmq(int l, int r)
{
    if (l > r)
        return INT_MAX;
    int k = logt[r - l + 1];
    return min(sparse[k][l], sparse[k][r - (1 << k) + 1]);
}

vector<vector<int>> tree;
void buildTree(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = {sa[l]};
        return;
    }
    int mid = (l + r) / 2;
    buildTree(node * 2, l, mid);
    buildTree(node * 2 + 1, mid + 1, r);
    tree[node].resize(tree[node * 2].size() + tree[node * 2 + 1].size());
    merge(tree[node * 2].begin(), tree[node * 2].end(), tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(), tree[node].begin());
}
int countLE(int node, int l, int r, int ql, int qr, int x)
{
    if (qr < l || r < ql || ql > qr)
        return 0;
    if (ql <= l && r <= qr)
        return (int)(upper_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin());
    int mid = (l + r) / 2;
    return countLE(node * 2, l, mid, ql, qr, x) + countLE(node * 2 + 1, mid + 1, r, ql, qr, x);
}
int countInRange(int ql, int qr, int lo, int hi)
{
    if (ql > qr || lo > hi)
        return 0;
    return countLE(1, 0, m - 1, ql, qr, hi) - countLE(1, 0, m - 1, ql, qr, lo - 1);
}

int n;

int findLeft(int pos, int k)
{
    int lo = 0, hi = pos;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        bool ok = (mid == pos) || (rmq(mid + 1, pos) >= k);
        if (ok)
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}
int findRight(int pos, int k)
{
    int lo = pos, hi = m - 1;
    while (lo < hi)
    {
        int mid = (lo + hi + 1) / 2;
        bool ok = (mid == pos) || (rmq(pos + 1, mid) >= k);
        if (ok)
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}

void fence()
{
    vector<ll> h(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    m = 2 * n;
    A.assign(m, 0);
    const ll SEP1 = 2000000000LL;
    const ll SEP2 = -2000000000LL;
    for (int i = 1; i <= n - 1; i++)
        A[i - 1] = h[i] - h[i + 1];
    A[n - 1] = SEP1;
    for (int i = 1; i <= n - 1; i++)
        A[n - 1 + i] = -(h[i] - h[i + 1]);
    A[2 * n - 1] = SEP2;

    buildSA();
    buildLCP();
    buildSparse();

    tree.resize(4 * m);
    buildTree(1, 0, m - 1);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int w = r - l + 1;
        if (w == 1)
        {
            cout << n - 1 << '\n';
            continue;
        }
        int k = w - 1;
        int pos = rnk[l - 1];
        int Lb = findLeft(pos, k);
        int Rb = findRight(pos, k);

        int totalD = countInRange(Lb, Rb, n, 2 * n - 2);

        int aMin = max(1, l - w + 1);
        int aMax = r;
        int pLo = n - 1 + aMin;
        int pHi = n - 1 + aMax;
        pLo = max(pLo, n);
        pHi = min(pHi, 2 * n - 2);
        int overlap = countInRange(Lb, Rb, pLo, pHi);

        int ans = totalD - overlap;

        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    fence();

    return 0;
}