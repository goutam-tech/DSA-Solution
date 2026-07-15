class Solution {
  public:
    int largestArea(int n, int m, int k, vector<vector<int>> &arr) {
        // code here
        vector<int> rows, cols;
        for(auto &p : arr){
            rows.push_back(p[0]);
            cols.push_back(p[1]);
        }
        
        sort(rows.begin(), rows.end());
        rows.erase(unique(rows.begin(), rows.end()), rows.end());
        sort(cols.begin(), cols.end());
        cols.erase(unique(cols.begin(), cols.end()), cols.end());
        
        int maxRowGap = 0, prev = 0;
        for(int r : rows){
            maxRowGap = max(maxRowGap, r - prev - 1);
            prev = r;
        }
        maxRowGap = max(maxRowGap, n - prev);
        
        int maxColGap = 0;
        prev = 0;
        for(int c : cols){
            maxColGap = max(maxColGap, c - prev - 1);
            prev = c;
        }
        maxColGap = max(maxColGap, m - prev);
              
        return maxRowGap * maxColGap;
    }
};