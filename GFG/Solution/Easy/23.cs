class Solution {
    public List<int> diagView(int[][] mat) {
        List<int> result = new List<int>();
        int n = mat.Length;
    
        for (int d = 0; d < 2 * n - 1; d++) {
            int startRow = d < n ? 0 : d - n + 1;
            int startCol = d < n ? d : n - 1;
        
            for (int i = startRow; i < n && startCol - (i - startRow) >= 0; i++) {
                result.Add(mat[i][startCol - (i - startRow)]);
            }
        }
    
        return result;
    }
}