class Solution
{
public:
    int maxDotProduct(vector<int> &a, vector<int> &b)
    {
        // code here
        int n = a.size(), m = b.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = i; j <= n; j++)
            {
                dp[i][j] = max(dp[i - 1][j - 1] + (long long)a[j - 1] * b[i - 1], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};