class Solution
{
public:
    vector<vector<int>> shortestDist(vector<vector<int>> &mat)
    {
        int n = mat.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        if (n == 1)
        {
            ans[0][0] = 1;
            return ans;
        }
        vector<vector<char>> canReach(n, vector<char>(n, 0));
        canReach[n - 1][n - 1] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == n - 1 && j == n - 1)
                    continue;
                if (mat[i][j] == 0)
                    continue;
                int k = mat[i][j];
                bool ok = false;
                for (int len = 1; len <= k && !ok; len++)
                {
                    if (j + len < n && canReach[i][j + len])
                        ok = true;
                }
                for (int len = 1; len <= k && !ok; len++)
                {
                    if (i + len < n && canReach[i + len][j])
                        ok = true;
                }
                canReach[i][j] = ok ? 1 : 0;
            }
        }
        if (!canReach[0][0])
        {
            return vector<vector<int>>(1, vector<int>(1, -1));
        }
        int ci = 0, cj = 0;
        ans[0][0] = 1;
        while (!(ci == n - 1 && cj == n - 1))
        {
            int k = mat[ci][cj];
            int ni = -1, nj = -1;
            for (int len = 1; len <= k && ni == -1; len++)
            {
                int tj = cj + len;
                if (tj < n && canReach[ci][tj])
                {
                    ni = ci;
                    nj = tj;
                    break;
                }
                int ti = ci + len;
                if (ti < n && canReach[ti][cj])
                {
                    ni = ti;
                    nj = cj;
                    break;
                }
            }
            ci = ni;
            cj = nj;
            ans[ci][cj] = 1;
        }
        return ans;
    }
};