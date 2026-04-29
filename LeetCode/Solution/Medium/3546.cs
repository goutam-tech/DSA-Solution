public class Solution {
    public bool CanPartitionGrid(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;

        long total = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                total += grid[i][j];
            }
        }

        if(total % 2 != 0) return false;
        long half = total / 2;

        long rowSum = 0;
        for(int i = 0; i < m - 1; i++){
            for(int j = 0; j < n; j++){
                rowSum += grid[i][j];
            }
            if(rowSum == half) return true;
        }

        long colSum = 0;
        for(int j = 0; j < n - 1; j++){
            for(int i = 0; i < m; i++){
                colSum += grid[i][j];
            }
            if(colSum == half) return true;
        }
        
        return false;
    }
}