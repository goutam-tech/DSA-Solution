class Solution {
  public:
    int findMaxProduct(vector<int>& arr) {
        int n = arr.size();
    
        if (n == 1) return arr[0];
    
        long long ans = 1;
        int mod = 1e9 + 7;
    
        int zeroCount = 0, negCount = 0;
        int maxNeg = INT_MIN, idxMaxNeg = -1;
    
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                zeroCount++;
            } 
            else if (arr[i] < 0) {
                negCount++;
                if (idxMaxNeg == -1 || arr[i] > maxNeg) {
                    maxNeg = arr[i];
                    idxMaxNeg = i;
                }
            }
        }
    
        if (zeroCount == n) return 0;
        if (negCount == 1 && zeroCount == n - 1) return 0;
    
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) continue;
    
            if (negCount % 2 == 1 && i == idxMaxNeg) continue;
    
            ans = ((ans * arr[i]) % mod + mod) % mod;
        }
    
        return ans;
    }
};