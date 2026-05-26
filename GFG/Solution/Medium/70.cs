class Solution {
    public int cntOnes(int[][] grid) {
        // code here
        int n = grid.Length, m = grid[0].Length;
        Queue<(int, int)> queue = new Queue<(int, int)>();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && (i == 0 || i == n -1 || j == 0 || j == m - 1)){
                    queue.Enqueue((i, j));
                    grid[i][j] = 0;
                }
            }
        }
        
        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};
        
        while(queue.Count > 0){
            var (r, c) = queue.Dequeue();
            for(int d = 0; d < 4; d++){
                int nr = r + dr[d], nc = c + dc[d];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
                    grid[nr][nc] = 0;
                    queue.Enqueue((nr, nc));
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1) count++;
            }
        }
        
        return count;
    }
}