#include <bits/stdc++.h>
using namespace std;

void cycles()
{
    long long k;
    cin >> k;

    static bool adj[105][105];
    int n = 0;
    int coreSize = 0;
    long long rem = k;

    while (rem > 0)
    {
        long long c2 = (long long)coreSize * (coreSize - 1) / 2;
        if (c2 <= rem)
        {
            int newv = n++;
            for (int c = 0; c < coreSize; c++)
            {
                adj[newv][c] = adj[c][newv] = true;
            }
            rem -= c2;
            coreSize++;
        }
        else
        {
            int x = coreSize;
            while ((long long)x * (x - 1) / 2 > rem)
                x--;
            int newv = n++;
            for (int c = 0; c < x; c++)
            {
                adj[newv][c] = adj[c][newv] = true;
            }
            rem -= (long long)x * (x - 1) / 2;
        }
    }

    if (n < 3)
        n = 3;

    cout << n << '\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (adj[i][j] ? '1' : '0');
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cycles();

    return 0;
}