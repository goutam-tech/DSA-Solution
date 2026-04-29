public class Solution {
    public int MaxProductPath(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        long[,] maxDp = new long[m,n];
        long[,] minDp = new long[m,n];

        maxDp[0,0] = minDp[0,0] = grid[0][0];

        for(int i = 1; i < m; i++)
            maxDp[i,0] = minDp[i,0] = maxDp[i-1,0] * grid[i][0];
        
        for(int j = 1; j < n; j++)
            maxDp[0,j] = minDp[0,j] = maxDp[0,j-1] * grid[0][j];
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                int v = grid[i][j];
                if(v >= 0){
                    maxDp[i,j] = Math.Max(maxDp[i-1,j], maxDp[i,j-1]) * v;
                    minDp[i,j] = Math.Min(minDp[i-1,j],minDp[i,j-1])*v;
                }
                else{
                    maxDp[i,j] = Math.Min(minDp[i-1,j], minDp[i,j-1])*v;
                    minDp[i,j] = Math.Max(maxDp[i-1,j],maxDp[i,j-1])*v;
                }
            }
        }

        long res = maxDp[m-1, n-1];
        if(res < 0) return -1;
        return (int)(res % (long)(1e9 + 7));
    }
}