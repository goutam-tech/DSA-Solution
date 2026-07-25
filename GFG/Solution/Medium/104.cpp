class Solution
{
public:
    int n, m, maxLen;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool valid(int x, int y, vector<vector<int>> &mat, vector<vector<bool>> &vis)
    {
        return x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 1 && !vis[x][y];
    }

    void dfs(vector<vector<int>> &mat, int x, int y, int xd, int yd, vector<vector<bool>> &vis, int len)
    {
        if (x == xd && y == yd)
        {
            maxLen = max(maxLen, len);
            return;
        }
        vis[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (valid(nx, ny, mat, vis))
                dfs(mat, nx, ny, xd, yd, vis, len + 1);
        }
        vis[x][y] = false;
    }

    int longestPath(vector<vector<int>> &mat, int xs, int ys, int xd, int yd)
    {
        n = mat.size();
        m = mat[0].size();
        if (mat[xs][ys] == 0 || mat[xd][yd] == 0)
            return -1;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        maxLen = -1;
        dfs(mat, xs, ys, xd, yd, vis, 0);
        return maxLen;
    }
};