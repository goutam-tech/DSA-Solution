class Solution
{
public:
    int countWays(int n, int m)
    {
        // code here.
        const long long mod = 1000000007;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = (i < m) ? 1 : (dp[i - 1] + dp[i - m]) % mod;
        }
        return (int)dp[n];
    }
};