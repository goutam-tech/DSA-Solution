class Solution
{
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    bool isValid(int row, int col, int n, int m)
    {
        return row >= 0 && col >= 0 && row < n && col < m;
    }

    void bfs(vector<vector<int>> &mat, int n, int m, queue<pair<int, int>> &q, vector<vector<bool>> &reachable)
    {
        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int newRow = row + dx[k];
                int newCol = col + dy[k];

                if (isValid(newRow, newCol, n, m) && !reachable[newRow][newCol] && mat[newRow][newCol] >= mat[row][col])
                {
                    reachable[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    int countCoordinates(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> reachP(n, vector<bool>(m, false));
        vector<vector<bool>> reachQ(n, vector<bool>(m, false));

        queue<pair<int, int>> stationP, stationQ;

        for (int col = 0; col < m; col++)
        {
            if (!reachP[0][col])
            {
                reachP[0][col] = true;
                stationP.push({0, col});
            }
        }

        for (int row = 0; row < n; row++)
        {
            if (!reachP[row][0])
            {
                reachP[row][0] = true;
                stationP.push({row, 0});
            }
        }

        for (int col = 0; col < m; col++)
        {
            if (!reachQ[n - 1][col])
            {
                reachQ[n - 1][col] = true;
                stationQ.push({n - 1, col});
            }
        }

        for (int row = 0; row < n; row++)
        {
            if (!reachQ[row][m - 1])
            {
                reachQ[row][m - 1] = true;
                stationQ.push({row, m - 1});
            }
        }

        bfs(mat, n, m, stationP, reachP);
        bfs(mat, n, m, stationQ, reachQ);

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (reachP[i][j] && reachQ[i][j])
                {
                    count++;
                }
            }
        }

        return count;
    }
};