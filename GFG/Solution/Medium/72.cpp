class Solution
{
public:
    int validGroups(string &s)
    {
        // code here
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(1001, -1));
        return dfs(s, 0, 0, dp);
    }

    int dfs(string &s, int idx, int prev, vector<vector<int>> &dp)
    {
        if (idx == s.size())
            return 1;
        if (dp[idx][prev] != -1)
            return dp[idx][prev];
        int ans = 0, sum = 0;
        for (int j = idx; j < s.size(); j++)
        {
            sum += s[j] - '0';
            if (sum >= prev)
                ans += dfs(s, j + 1, sum, dp);
        }
        return dp[idx][prev] = ans;
    }
};