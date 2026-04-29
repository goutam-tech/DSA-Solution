public class Solution {
    public bool HasValidPath(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        
        HashSet<int>[] opens = new HashSet<int>[] {
            new HashSet<int>(),
            new HashSet<int> { 1, 4, 6 },
            new HashSet<int> { 1, 3, 5 },
            new HashSet<int> { 2, 3, 4 },
            new HashSet<int> { 2, 5, 6 }
        };
        
        int[][] dirs = new int[][] {
            new int[] { 0,  1, 1, 2 },
            new int[] { 0, -1, 2, 1 },
            new int[] { 1,  0, 3, 4 },
            new int[] {-1,  0, 4, 3 }
        };
        
        bool[][] visited = new bool[m][];
        for (int i = 0; i < m; i++) visited[i] = new bool[n];
        
        Queue<(int, int)> queue = new Queue<(int, int)>();
        queue.Enqueue((0, 0));
        visited[0][0] = true;
        
        while (queue.Count > 0) {
            var (r, c) = queue.Dequeue();
            if (r == m - 1 && c == n - 1) return true;
            
            foreach (var d in dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n
                    && !visited[nr][nc]
                    && opens[d[2]].Contains(grid[r][c])
                    && opens[d[3]].Contains(grid[nr][nc])) {
                    visited[nr][nc] = true;
                    queue.Enqueue((nr, nc));
                }
            }
        }
        
        return false;
    }
}