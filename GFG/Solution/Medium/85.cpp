class Solution {
public:
    int findCoverage(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> rowPrefix(rows, vector<int>(cols + 1, 0));
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                rowPrefix[i][j + 1] = rowPrefix[i][j] + mat[i][j];

        vector<vector<int>> colPrefix(cols, vector<int>(rows + 1, 0));
        for (int j = 0; j < cols; j++)
            for (int i = 0; i < rows; i++)
                colPrefix[j][i + 1] = colPrefix[j][i] + mat[i][j];

        long long total = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 0) {
                    int left = rowPrefix[i][j];
                    int right = rowPrefix[i][cols] - rowPrefix[i][j + 1];
                    int up = colPrefix[j][i];
                    int down = colPrefix[j][rows] - colPrefix[j][i + 1];
                    total += (left > 0) + (right > 0) + (up > 0) + (down > 0);
                }
            }
        }
        return (int)total;
    }
};