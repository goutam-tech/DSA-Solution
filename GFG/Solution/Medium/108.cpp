class Solution
{
public:
    int countWays(int n, int sum)
    {
        const int MOD = 1e9 + 7;
        if (sum == 0 || sum > 9 * n)
            return -1;
        vector<vector<long long>> dp(n + 1, vector<long long>(sum + 1, 0));
        for (int j = 1; j <= min(9, sum); j++)
        {
            dp[1][j] = 1;
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                long long ways = 0;
                for (int d = 0; d <= 9 && d <= j; d++)
                {
                    ways += dp[i - 1][j - d];
                }
                dp[i][j] = ways % MOD;
            }
        }
        return (int)dp[n][sum];
    }
};