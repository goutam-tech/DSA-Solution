class Solution {
  public:
    int minimumCost(vector<int> &cost, int w) {
        vector<int> dp(w + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= w; i++) {
            for (int j = 0; j < (int)cost.size() && j < i; j++) {
                if (cost[j] != -1 && dp[i - j - 1] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - j - 1] + cost[j]);
            }
        }
        return dp[w] == INT_MAX ? -1 : dp[w];
    }
};