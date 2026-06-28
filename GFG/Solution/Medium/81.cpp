class Solution
{
public:
    vector<int> exitPoint(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size(), m = mat[0].size();
        int r = 0, c = 0;
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        int dir = 0;

        while (r >= 0 && r < n && c >= 0 && c < m)
        {
            if (mat[r][c] == 1)
            {
                mat[r][c] = 0;
                dir = (dir + 1) % 4;
            }
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                break;
            r = nr;
            c = nc;
        }

        return {r, c};
    }
};