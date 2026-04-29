public class Solution {
    public int NumberOfSubmatrices(char[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        int[,] px = new int[m,n];
        int[,] pd = new int[m,n];
        int result = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int xVal = grid[i][j] == 'X' ? 1 : 0;
                int dVal = grid[i][j] == 'X' ? 1 : grid[i][j] == 'Y' ? -1 : 0;
                px[i,j] = xVal;
                pd[i,j] = dVal;

                if(i > 0) { 
                    px[i,j] += px[i - 1, j];
                    pd[i, j] += pd[i - 1, j];
                }

                if(j > 0) { 
                    px[i,j] += px[i, j - 1];
                    pd[i, j] += pd[i, j - 1];
                }

                if(i > 0 && j > 0){ 
                    px[i,j] -= px[i - 1, j - 1];
                    pd[i, j] -= pd[i - 1, j - 1];
                }

                if(pd[i, j] == 0 && px[i,j] > 0) result++;
            }
        }

        return result;
    }
}