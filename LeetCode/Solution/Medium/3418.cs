public class Solution {
    public int MaximumAmount(int[][] coins) {
        int m = coins.Length;
        int n = coins[0].Length;
        
        int INF = int.MinValue / 2;
        int[,,] dp = new int[m, n, 3];
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < 3; k++)
                    dp[i, j, k] = INF;
        
        int startVal = coins[0][0];
        dp[0, 0, 0] = startVal;
        if (startVal < 0) dp[0, 0, 1] = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                int val = coins[i][j];
                for (int k = 0; k < 3; k++) {
                    int best = INF;
                    if (i > 0 && dp[i-1, j, k] != INF)
                        best = Math.Max(best, dp[i-1, j, k]);
                    if (j > 0 && dp[i, j-1, k] != INF)
                        best = Math.Max(best, dp[i, j-1, k]);
                    
                    if (best == INF) continue;
                    
                    dp[i, j, k] = Math.Max(dp[i, j, k], best + val);
                    
                    if (val < 0 && k < 2) {
                        dp[i, j, k+1] = Math.Max(dp[i, j, k+1], best);
                    }
                }
            }
        }
        
        int ans = INF;
        for (int k = 0; k < 3; k++)
            ans = Math.Max(ans, dp[m-1, n-1, k]);
        
        return ans;
    }
}