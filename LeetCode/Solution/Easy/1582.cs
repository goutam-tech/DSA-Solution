public class Solution {
    public int NumSpecial(int[][] mat) {
        int m = mat.Length, n = mat[0].Length;
        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1 && IsSpecial(mat,i,j,m,n))
                  count++;
            }
        }
        return count;
    }

    private bool IsSpecial(int[][] mat, int row, int col, int m, int n){
        for(int j = 0; j < n; j++){
            if(j != col && mat[row][j] == 1) return false;
        }

        for(int i = 0; i < m; i++){
            if(i != row && mat[i][col] == 1) return false;
        }

        return true;
    }
}