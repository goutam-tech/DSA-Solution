class Solution
{
public:
    int maximumSum(vector<vector<int>> &mat, int k)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<long long>> pre(n + 1, vector<long long>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                pre[i][j] = mat[i - 1][j - 1] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            }
        }
        long long best = LLONG_MIN;
        for (int i = k; i <= n; i++)
        {
            for (int j = k; j <= m; j++)
            {
                long long sum = pre[i][j] - pre[i - k][j] - pre[i][j - k] + pre[i - k][j - k];
                best = max(best, sum);
            }
        }
        return (int)best;
    }
};