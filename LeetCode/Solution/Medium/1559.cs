public class Solution {
    public bool ContainsCycle(char[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        int[] parent = new int[m * n];
        int[] rank = new int[m * n];
        
        for(int i = 0; i < m * n; i++){
            parent[i] = i;
        }

        int Find(int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }

        bool Union(int x, int y){
            int px = Find(x), py = Find(y);
            if(px == py) return true;
            if(rank[px] < rank[py]) (px, py) = (py, px);
            parent[py] = px;
            if(rank[px] == rank[py]) rank[px]++;
            return false;
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (i + 1 < m && grid[i + 1][j] == grid[i][j])
                    if (Union(i * n + j, (i + 1) * n + j)) return true;
                if (j + 1 < n && grid[i][j + 1] == grid[i][j])
                    if (Union(i * n + j, i * n + j + 1)) return true;
            }
        }

        return false;
    }
}