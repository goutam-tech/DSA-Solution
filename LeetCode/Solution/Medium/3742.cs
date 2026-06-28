public class Solution {
    public int MaxPathScore(int[][] grid, int k) {
        int m = grid.Length, n = grid[0].Length;

        int cellCost(int v) => v == 0 ? 0 : 1;

        int[,,] dp = new int[m, n, k + 1];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int c = 0; c <= k; c++){
                    dp[i,j,c] = -1;
                }
            }
        }

        int startCost = cellCost(grid[0][0]);
        if(startCost <= k){
            dp[0, 0, startCost] = grid[0][0];
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {
                    if (dp[i, j, c] == -1) continue;
                    
                    int[] dirs = { 0, 1, 1, 0 };
                    for (int d = 0; d < 2; d++) {
                        int ni = i + dirs[d * 2];
                        int nj = j + dirs[d * 2 + 1];
                        if (ni >= m || nj >= n) continue;
                        
                        int nc = c + cellCost(grid[ni][nj]);
                        if (nc > k) continue;
                        
                        int ns = dp[i, j, c] + grid[ni][nj];
                        if (ns > dp[ni, nj, nc])
                            dp[ni, nj, nc] = ns;
                    }
                }
            }
        }

        int ans = -1;
        for(int c = 0; c <= k; c++){
            if(dp[m - 1, n - 1, c] > ans){
                ans = dp[m - 1, n - 1, c];
            }
        }

        return ans;
    }
}