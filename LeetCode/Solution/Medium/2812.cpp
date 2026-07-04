class Solution
{
public:
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> safe(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    safe[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && safe[nx][ny] == -1)
                {
                    safe[nx][ny] = safe[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        vector<vector<int>> dist(n, vector<int>(n, -1));
        priority_queue<tuple<int, int, int>> pq;
        pq.push({safe[0][0], 0, 0});
        dist[0][0] = safe[0][0];
        while (!pq.empty())
        {
            auto [d, x, y] = pq.top();
            pq.pop();
            if (d < dist[x][y])
                continue;
            if (x == n - 1 && y == n - 1)
                return d;
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                {
                    int nd = min(d, safe[nx][ny]);
                    if (nd > dist[nx][ny])
                    {
                        dist[nx][ny] = nd;
                        pq.push({nd, nx, ny});
                    }
                }
            }
        }

        return dist[n - 1][n - 1];
    }
};