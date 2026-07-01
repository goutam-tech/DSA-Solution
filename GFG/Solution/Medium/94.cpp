class Solution
{
public:
    int countStrings(int n, int k)
    {
        const long long MOD = 1000000007;
        vector<long long> dp0(k + 1, 0), dp1(k + 1, 0);
        dp0[0] = 1;
        dp1[0] = 1;
        vector<long long> ndp0(k + 1), ndp1(k + 1);
        for (int i = 2; i <= n; i++)
        {
            ndp0[0] = (dp0[0] + dp1[0]) % MOD;
            ndp1[0] = dp0[0];
            for (int j = 1; j <= k; j++)
            {
                ndp0[j] = (dp0[j] + dp1[j]) % MOD;
                ndp1[j] = (dp0[j] + dp1[j - 1]) % MOD;
            }
            swap(dp0, ndp0);
            swap(dp1, ndp1);
        }
        return (int)((dp0[k] + dp1[k]) % MOD);
    }
};