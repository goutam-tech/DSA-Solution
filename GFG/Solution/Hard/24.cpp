class Solution {
  public:
    int countSpanTree(int n, vector<vector<int>>& edges) {
        // code here
        vector<vector<double>> L(n, vector<double>(n, 0));
        
        for(auto& e : edges){
            int u = e[0], v = e[1];
            L[u][u]++;
            L[v][v]++;
            L[u][v]--;
            L[v][u]--;
        }
        
        int sz = n - 1;
        vector<vector<double>> mat(sz, vector<double>(sz, 0));
        for(int i = 0; i < sz; i++){
            for(int j = 0; j < sz; j++){
                mat[i][j] = L[i][j];
            }
        }
        
        double det = 1.0;
        for(int col = 0; col < sz; col++){
            int pivot = -1;
            for(int row = col; row < sz; row++){
                if(fabs(mat[row][col]) > 1e-9){
                    pivot = row;
                    break;
                }
            }
            if (pivot == -1) return 0;
            if (pivot != col) {
                swap(mat[pivot], mat[col]);
                det *= -1;
            }
            det *= mat[col][col];
            for (int row = col + 1; row < sz; row++) {
                double factor = mat[row][col] / mat[col][col];
                for (int k = col; k < sz; k++)
                    mat[row][k] -= factor * mat[col][k];
            }
        }
        
        return (int)round(fabs(det));
    }
};