class Solution {
    public int optimalKeys(int n) {
        // code here
        var dp = new int[n + 1];
        dp[0] = 0;
        
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i - 1] + 1;
            
            for(int factor = 2; factor <= i - 2; factor++){
                dp[i] = Math.Max(dp[i], dp[i - factor - 1] * factor);
            }
        }
        
        return dp[n];
    }
}