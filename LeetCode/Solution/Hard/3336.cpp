class Solution
{
public:
    int subsequencePairCount(vector<int> &nums)
    {
        const int MOD = 1e9 + 7;
        int maxVal = *max_element(nums.begin(), nums.end());
        int V = maxVal + 1;

        vector<vector<int>> dp(V, vector<int>(V, 0));
        dp[0][0] = 1;

        for (int x : nums)
        {
            vector<vector<int>> ndp(V, vector<int>(V, 0));
            for (int g1 = 0; g1 < V; g1++)
            {
                for (int g2 = 0; g2 < V; g2++)
                {
                    int val = dp[g1][g2];
                    if (!val)
                        continue;

                    ndp[g1][g2] = (ndp[g1][g2] + val) % MOD;

                    int ng1 = (g1 == 0) ? x : __gcd(g1, x);
                    ndp[ng1][g2] = (ndp[ng1][g2] + val) % MOD;

                    int ng2 = (g2 == 0) ? x : __gcd(g2, x);
                    ndp[g1][ng2] = (ndp[g1][ng2] + val) % MOD;
                }
            }
            dp = move(ndp);
        }

        long long ans = 0;
        for (int g = 1; g < V; g++)
        {
            ans = (ans + dp[g][g]) % MOD;
        }

        return (int)ans;
    }
};