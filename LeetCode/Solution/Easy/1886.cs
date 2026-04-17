public class Solution {
    public bool FindRotation(int[][] mat, int[][] target) {
        int n = mat.Length;
        bool[] possible = new[] {true, true, true, true};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] != target[i][j]) possible[0] = false;
                if(mat[i][j] != target[n -1 -j][i]) possible[1] = false;
                if(mat[i][j] != target[n - 1 -i][n - 1 - j]) possible[2] = false;
                if(mat[i][j] != target[j][n - 1 - i]) possible[3] = false;
            }
        }

        return possible[0] || possible[1] || possible[2] || possible[3];
    }
}