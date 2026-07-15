class Solution
{
public:
    bool divisibleByK(vector<int> &arr, int k)
    {
        vector<bool> dp(k, false);
        for (int num : arr)
        {
            vector<bool> ndp = dp;
            int r = ((num % k) + k) % k;
            ndp[r] = true;
            for (int j = 0; j < k; j++)
            {
                if (dp[j])
                {
                    ndp[(j + r) % k] = true;
                }
            }
            dp = ndp;
        }
        return dp[0];
    }
};