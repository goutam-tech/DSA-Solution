class Solution
{
public:
    int waysToIncreaseLCSBy1(string &s1, string &s2)
    {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp1(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp1[i][j] = dp1[i - 1][j - 1] + 1;
                else
                    dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]);
            }
        }
        vector<vector<int>> dp2(n + 2, vector<int>(m + 2, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (s1[i] == s2[j])
                    dp2[i][j] = dp2[i + 1][j + 1] + 1;
                else
                    dp2[i][j] = max(dp2[i + 1][j], dp2[i][j + 1]);
            }
        }
        int LCS = dp1[n][m];
        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            vector<int> best(26, -1);
            for (int j = 0; j < m; j++)
            {
                int c = s2[j] - 'a';
                int val = dp1[i][j] + dp2[i][j + 1];
                if (val > best[c])
                    best[c] = val;
            }
            for (int c = 0; c < 26; c++)
            {
                if (best[c] == LCS)
                    ans++;
            }
        }
        return ans;
    }
};