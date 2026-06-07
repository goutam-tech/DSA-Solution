class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        
        for(int i = n - 2; i >= 0; i--){
            dp[i] = dp[i + 1];
            if(arr[i + 1] - arr[i] < k){
                dp[i] = max(dp[i], arr[i] + arr[i + 1] + dp[i + 2]);
            }
        }
        return dp[0];
    }
};