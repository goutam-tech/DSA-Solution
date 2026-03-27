class Solution {
    public int maxChocolate(int[,] grid) {
        int n = grid.GetLength(0);
        int m = grid.GetLength(1);
        
        int[,,] dp = new int[n, m, m];
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < m; k++)
                    dp[i, j, k] = int.MinValue;
        
        dp[0, 0, m - 1] = (m == 1) ? grid[0, 0] : grid[0, 0] + grid[0, m - 1];
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = j; k < m; k++) {
                    int best = int.MinValue;
                    for (int dj = -1; dj <= 1; dj++) {
                        for (int dk = -1; dk <= 1; dk++) {
                            int pj = j - dj;
                            int pk = k - dk;
                            if (pj < 0 || pj >= m || pk < 0 || pk >= m) continue;
                            if (pj > pk) continue;
                            if (dp[i - 1, pj, pk] == int.MinValue) continue;
                            best = Math.Max(best, dp[i - 1, pj, pk]);
                        }
                    }
                    if (best == int.MinValue) continue;
                    int collected = (j == k) ? grid[i, j] : grid[i, j] + grid[i, k];
                    dp[i, j, k] = best + collected;
                }
            }
        }
        
        int ans = 0;
        for (int j = 0; j < m; j++)
            for (int k = j; k < m; k++)
                if (dp[n - 1, j, k] != int.MinValue)
                    ans = Math.Max(ans, dp[n - 1, j, k]);
        
        return ans;
    }
}