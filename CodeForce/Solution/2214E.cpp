#include <bits/stdc++.h>

using namespace std;

const int MX = 1e9;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(n, MX));
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            for (int j = 0; j < n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (dist[0][i] >= MX)
        {
            cout << "-1\n";
        }
        else
        {
            cout << dist[0][i] << "\n";
        }
    }
}