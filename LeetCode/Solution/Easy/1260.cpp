class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        long long total = (long long)m * n;
        k %= total;
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                long long idx = ((long long)i * n + j + k) % total;
                int ni = idx / n, nj = idx % n;
                res[ni][nj] = grid[i][j];
            }
        }

        return res;
    }
};