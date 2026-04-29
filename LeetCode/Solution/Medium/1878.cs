public class Solution {
    private SortedSet<int> top3 = new SortedSet<int>();
    
    private void AddToTop3(int val) {
        top3.Add(val);
        if (top3.Count > 3) top3.Remove(top3.Min);
    }
    
    public int[] GetBiggestThree(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        top3.Clear();
        
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                AddToTop3(grid[r][c]);
                int maxSize = Math.Min(Math.Min(r, m - 1 - r), Math.Min(c, n - 1 - c));
                for (int size = 1; size <= maxSize; size++) {
                    int sum = 0;
                    for (int i = 0; i < size; i++) {
                        sum += grid[r - size + i][c + i];
                        sum += grid[r + i][c + size - i];
                        sum += grid[r + size - i][c - i];
                        sum += grid[r - i][c - size + i];
                    }
                    AddToTop3(sum);
                }
            }
        }
        
        int[] result = new int[top3.Count];
        int idx = top3.Count - 1;
        foreach (int v in top3) result[idx--] = v;
        return result;
    }
}