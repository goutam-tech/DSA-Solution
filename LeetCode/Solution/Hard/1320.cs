using System;

public class Solution {
    public int MinimumDistance(string word) {
        //int n = word.Length;
        int[,] dp = new int[27, 27];

        for (int i = 0; i < 27; i++)
            for (int j = 0; j < 27; j++)
                dp[i, j] = int.MaxValue;

        dp[26, 26] = 0;

        foreach (char ch in word) {
            int c = ch - 'A';
            int[,] next = new int[27, 27];

            for (int i = 0; i < 27; i++)
                for (int j = 0; j < 27; j++)
                    next[i, j] = int.MaxValue;

            for (int f1 = 0; f1 < 27; f1++) {
                for (int f2 = 0; f2 < 27; f2++) {
                    if (dp[f1, f2] == int.MaxValue) continue;

                    int cost1 = dp[f1, f2] + (f1 == 26 ? 0 : Dist(f1, c));
                    next[c, f2] = Math.Min(next[c, f2], cost1);

                    int cost2 = dp[f1, f2] + (f2 == 26 ? 0 : Dist(f2, c));
                    next[f1, c] = Math.Min(next[f1, c], cost2);
                }
            }

            dp = next;
        }

        int res = int.MaxValue;
        for (int i = 0; i < 27; i++)
            for (int j = 0; j < 27; j++)
                res = Math.Min(res, dp[i, j]);

        return res;
    }

    private int Dist(int a, int b) {
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return Math.Abs(x1 - x2) + Math.Abs(y1 - y2);
    }
}