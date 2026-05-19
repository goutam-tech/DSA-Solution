class Solution {
    public bool isWordExist(char[,] mat, string word) {
        int n = mat.GetLength(0); 
        int m = mat.GetLength(1); 
        bool[,] visited = new bool[n, m]; 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < m; j++) { 
                if (DFS(mat, word, 0, i, j, visited)) return true; 
            } 
        } 
        return false;
    }
    private bool DFS(char[,] mat, string word, int index, int x, int y, bool[,] visited) { 
        if (index == word.Length) return true; 
        if (x < 0 || y < 0 || x >= mat.GetLength(0) || y >= mat.GetLength(1)) return false; 
        if (visited[x, y] || mat[x, y] != word[index]) return false; 
        visited[x, y] = true; 
        bool found = DFS(mat, word, index + 1, x + 1, y, visited) || 
                     DFS(mat, word, index + 1, x - 1, y, visited) || 
                     DFS(mat, word, index + 1, x, y + 1, visited) || 
                     DFS(mat, word, index + 1, x, y - 1, visited); 
        visited[x, y] = false;  
        return found; 
    }
}