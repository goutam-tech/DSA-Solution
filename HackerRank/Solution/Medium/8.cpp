/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s)
{
    vector<vector<int>> AdjList(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }

    vector<int> status(n + 1, -1);
    queue<int> Q;
    Q.push(s);
    status[s] = 0;

    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        for (int j = 0; j < AdjList[x].size(); j++)
        {
            int y = AdjList[x][j];
            if (status[y] == -1)
            {
                status[y] = status[x] + 6;
                Q.push(y);
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (i != s)
        {
            ans.push_back(status[i]);
        }
    }
    return ans;
}