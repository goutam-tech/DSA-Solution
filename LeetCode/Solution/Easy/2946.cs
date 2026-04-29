namespace Easy;

public class Solution {
    public bool AreSimilar(int[][] mat, int k) {
        int m = mat.Length;
        int n = mat[0].Length;
        
        for (int i = 0; i < m; i++) {
            int shift = k % n;
            if (shift == 0) continue;
            
            for (int j = 0; j < n; j++) {
                int newJ = i % 2 == 0 ? ((j - shift) % n + n) % n : (j + shift) % n;
                if (mat[i][j] != mat[i][newJ]) return false;
            }
        }
        return true;
    }
}