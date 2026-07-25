/*
 * Complete the 'connectedCell' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */

int connectedCell(vector<vector<int>> matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int ans = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                visited[i][j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                int curr = 0;
                q.push({i, j});
                while (!q.empty())
                {
                    curr++;
                    pair<int, int> p = q.front();
                    visited[p.first][p.second] = true;
                    q.pop();

                    int rowStart = max(p.first - 1, 0);
                    int colStart = max(p.second - 1, 0);
                    int rowEnd = min(n - 1, p.first + 1);
                    int colEnd = min(m - 1, p.second + 1);

                    for (int r = rowStart; r <= rowEnd; r++)
                    {
                        for (int c = colStart; c <= colEnd; c++)
                        {
                            if (!visited[r][c])
                            {
                                visited[r][c] = true;
                                q.push({r, c});
                            }
                        }
                    }
                }
                ans = max(curr, ans);
            }
        }
    }

    return ans;
}