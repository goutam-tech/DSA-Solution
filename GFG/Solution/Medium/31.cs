class Solution {
    public int orangesRot(int[,] mat) {
        // code here
        int rows = mat.GetLength(0);
        int cols = mat.GetLength(1);
        var queue = new Queue<(int, int)>();
        int fresh = 0;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(mat[i, j] == 2) queue.Enqueue((i,j));
                else if(mat[i,j] == 1) fresh++;
            }
        }
        
        if(fresh == 0) return 0;
        
        int[] dr = {-1,1,0,0};
        int[] dc = {0,0,-1,1};
        int time = 0;
        
        while(queue.Count > 0){
            int size = queue.Count;
            bool rotted = false;
            for(int k = 0; k < size; k++){
                var (r,c) = queue.Dequeue();
                for(int d = 0; d < 4; d++){
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && mat[nr,nc] == 1){
                        mat[nr, nc] = 2;
                        fresh--;
                        queue.Enqueue((nr,nc));
                        rotted = true;
                    }
                }
            }
            if(rotted) time++;
        }
        
        return fresh == 0 ? time : -1;
    }
}