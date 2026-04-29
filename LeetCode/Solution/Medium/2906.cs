public class Solution {
    public int[][] ConstructProductMatrix(int[][] grid) {
        int n = grid.Length, m = grid[0].Length;
        int total = n * m;
        const int MOD = 12345;

        int[][] p = new int[n][];
        for(int i = 0; i < n; i++) p[i] = new int[m];

        long[] prefix = new long[total + 1];
        long[] suffix = new long[total + 1];

        prefix[0] = 1;
        for(int i = 0; i < total; i++){
            int r = i / m, c = i % m;
            prefix[i + 1] = prefix[i] * grid[r][c] % MOD; 
        }

        suffix[total] = 1;
        for(int i = total - 1; i >= 0; i--){
            int r = i / m, c = i % m;
            suffix[i] = suffix[i + 1] * grid[r][c]  % MOD;
        }

        for(int i = 0; i < total; i++){
            int r = i / m, c = i % m;
            p[r][c] = (int)(prefix[i] * suffix[i + 1] % MOD);
        }
        return p;
    }
}