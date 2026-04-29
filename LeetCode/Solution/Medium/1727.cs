public class Solution {
    public int LargestSubmatrix(int[][] matrix) {
        int m = matrix.Length, n = matrix[0].Length;

        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1)
                  matrix[i][j] += matrix[i - 1][j];
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            int[] row = (int[])matrix[i].Clone();
            Array.Sort(row, (a,b) => b - a);
            for(int j = 0; j < n && row[j] > 0; j++){
                ans = Math.Max(ans, row[j] * (j + 1));
            }
        }

        return ans;
    }
}