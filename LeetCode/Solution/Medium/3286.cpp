class Solution
{
public:
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        deque<pair<int, int>> dq;
        dist[0][0] = grid[0][0];
        dq.push_back({0, 0});
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        while (!dq.empty())
        {
            auto [x, y] = dq.front();
            dq.pop_front();
            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                int cost = grid[nx][ny];
                if (dist[x][y] + cost < dist[nx][ny])
                {
                    dist[nx][ny] = dist[x][y] + cost;
                    if (cost == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }
        return health - dist[n - 1][m - 1] >= 1;
    }
};