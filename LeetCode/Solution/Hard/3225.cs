using System;

public class Solution
{
    private long?[,,] dp;

    private long Solve(int[][] grid, int col, int last1, int last2)
    {
        int n = grid.Length;

        if (col >= n)
        {
            return 0;
        }

        if (dp[col, last1, last2] != null)
        {
            return dp[col, last1, last2].Value;
        }

        long fromLast2 = 0;

        for (int i = 0; i < last2; i++)
        {
            fromLast2 += grid[i][col];
        }

        long ans = fromLast2 + Solve(grid, col + 1, 0, last1);

        long sum = 0;

        if (col + 1 < n)
        {
            for (int i = last1; i < n; i++)
            {
                sum += grid[i][col];
                ans = Math.Max(ans, sum + Solve(grid, col + 1, i + 1, 0));
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i < last2)
            {
                fromLast2 -= grid[i][col];
            }
            ans = Math.Max(ans, fromLast2 + Solve(grid, col + 1, 0, i + 1));
        }

        dp[col, last1, last2] = ans;
        return ans;
    }

    public long MaximumScore(int[][] grid)
    {
        int n = grid.Length;
        dp = new long?[n + 1, n + 1, n + 1];
        return Solve(grid, 0, 0, 0);
    }
}