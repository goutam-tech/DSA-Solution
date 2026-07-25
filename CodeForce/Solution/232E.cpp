#include <bits/stdc++.h>
using namespace std;
const int MAXM = 505;

int n, m, q;
vector<string> g;
vector<vector<int>> blackPrefix;
vector<int> X1, Y1, X2, Y2;
vector<char> ansArr;

void quickTortoise(int lo, int hi, vector<int> ids)
{
    if (ids.empty())
        return;
    if (lo == hi)
    {
        for (int id : ids)
        {
            ansArr[id] = (blackPrefix[lo][Y2[id]] - blackPrefix[lo][Y1[id] - 1] == 0) ? 1 : 0;
        }
        return;
    }

    int mid = (lo + hi) / 2;
    int R1 = mid - lo + 1, R2 = hi - mid;
    vector<int> leftIds, rightIds;
    {
        vector<vector<bitset<MAXM>>> down(R1, vector<bitset<MAXM>>(m + 1));
        for (int i = R1 - 1; i >= 0; i--)
        {
            int row = lo + i;
            for (int y = m; y >= 1; y--)
            {
                if (g[row][y - 1] == '#')
                    continue;
                bitset<MAXM> val;
                if (i == R1 - 1)
                    val.set(y);
                if (y + 1 <= m)
                    val |= down[i][y + 1];
                if (i + 1 <= R1 - 1)
                    val |= down[i + 1][y];
                down[i][y] = val;
            }
        }
        vector<vector<bitset<MAXM>>> up(R2, vector<bitset<MAXM>>(m + 1));
        for (int i = 0; i < R2; i++)
        {
            int row = mid + 1 + i;
            for (int y = 1; y <= m; y++)
            {
                if (g[row][y - 1] == '#')
                    continue;
                bitset<MAXM> val;
                if (i == 0)
                    val.set(y);
                if (y - 1 >= 1)
                    val |= up[i][y - 1];
                if (i - 1 >= 0)
                    val |= up[i - 1][y];
                up[i][y] = val;
            }
        }
        for (int id : ids)
        {
            int x1v = X1[id], x2v = X2[id];
            if (x2v <= mid)
                leftIds.push_back(id);
            else if (x1v > mid)
                rightIds.push_back(id);
            else
            {
                int i1 = x1v - lo, i2 = x2v - (mid + 1);
                ansArr[id] = (down[i1][Y1[id]] & up[i2][Y2[id]]).any() ? 1 : 0;
            }
        }
    }

    quickTortoise(lo, mid, move(leftIds));
    quickTortoise(mid + 1, hi, move(rightIds));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    g.assign(n + 1, "");

    for (int i = 1; i <= n; i++)
    {
        cin >> g[i];
    }

    blackPrefix.assign(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            blackPrefix[i][j] = blackPrefix[i][j - 1] + (g[i][j - 1] == '#' ? 1 : 0);
        }
    }

    cin >> q;
    X1.resize(q);
    Y1.resize(q);
    X2.resize(q);
    Y2.resize(q);
    ansArr.assign(q, 0);

    for (int i = 0; i < q; i++)
    {
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
    }
    vector<int> allIds(q);

    iota(allIds.begin(), allIds.end(), 0);

    quickTortoise(1, n, move(allIds));

    string out;
    out.reserve((size_t)q * 4);

    for (int i = 0; i < q; i++)
    {
        out += (ansArr[i] ? "Yes\n" : "No\n");
    }

    cout << out;

    return 0;
}