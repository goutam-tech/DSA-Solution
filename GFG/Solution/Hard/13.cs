class Solution {
    public int countSquare(int[,] mat, int x) {
        int n = mat.GetLength(0);
        int m = mat.GetLength(1);
        
        int[,] prefix = new int[n + 1, m + 1];
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                prefix[i,j] = mat[i - 1, j - 1] + prefix[i - 1, j] + prefix[i, j - 1] - prefix[i - 1, j - 1];
            }
        }
        
        int count = 0;
        int maxSize = Math.Min(n,m);
        
        for(int size = 1; size <= maxSize; size++){
            for(int i = 1; i<= n - size + 1; i++){
                for(int j = 1; j <= m - size + 1; j++){
                    int r2 = i + size - 1;
                    int c2 = j + size - 1;
                    
                    int sum = prefix[r2,c2] - prefix[i - 1, c2] - prefix[r2, j - 1] + prefix[i - 1, j - 1];
                    
                    if(sum == x) count++;
                }
            }
        }
        
        return count;
    }
}