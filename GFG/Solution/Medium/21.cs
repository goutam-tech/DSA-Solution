class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        long long result = 0;
        int n = arr.size();
        
        for(int b = 0; b < 32; b++){
            long long ones = 0;
            for(int i = 0; i < n; i++){
                if(arr[i] & (1 << b)){
                    ones++;
                }
            }
            long long zeros = n - ones;
            result += ones * zeros * (1LL << b);
        }
        
        return result;
    }
};