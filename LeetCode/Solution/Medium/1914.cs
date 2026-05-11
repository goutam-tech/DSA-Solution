public class Solution {
    public int[][] RotateGrid(int[][] grid, int k) {
        int m = grid.Length, n = grid[0].Length;
        int layers = Math.Min(m, n) / 2;

        for(int layer = 0; layer < layers; layer++){
            var elements = new List<int>();
            int top = layer, bottom = m - 1 - layer;
            int left = layer, right = n - 1 - layer;

            for(int col = left; col <= right; col++) elements.Add(grid[top][col]);
            for(int row = top + 1; row <= bottom; row++) elements.Add(grid[row][right]);
            for(int col = right - 1; col >= left; col--) elements.Add(grid[bottom][col]);
            for(int row = bottom - 1; row >= top + 1; row--) elements.Add(grid[row][left]);

            int len = elements.Count;
            int shift = k % len;
            var rotated = new List<int>();

            for (int i = shift; i < len; i++) rotated.Add(elements[i]);
            for (int i = 0; i < shift; i++) rotated.Add(elements[i]);
            
            int idx = 0;
            for (int col = left; col <= right; col++) grid[top][col] = rotated[idx++];
            for (int row = top + 1; row <= bottom; row++) grid[row][right] = rotated[idx++];
            for (int col = right - 1; col >= left; col--) grid[bottom][col] = rotated[idx++];
            for (int row = bottom - 1; row >= top + 1; row--) grid[row][left] = rotated[idx++];
        }

        return grid;
    }
}