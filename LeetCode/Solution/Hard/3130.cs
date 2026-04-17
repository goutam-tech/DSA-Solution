public class Solution {
    public int NumberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1_000_000_007;

        long[,,] dp = new long[zero + 1, one + 1, 2];

        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {
                if (i == 0 && j == 0) continue;

                if (i > 0 && j == 0) {
                    // Only zeros placed: valid only if i <= limit
                    dp[i, j, 0] = (i <= limit) ? 1 : 0;
                } else if (i > 0) {
                    dp[i, j, 0] = (dp[i - 1, j, 0] + dp[i - 1, j, 1]) % MOD;
                    if (i - limit - 1 >= 0)
                        dp[i, j, 0] = (dp[i, j, 0] - dp[i - limit - 1, j, 1] + MOD) % MOD;
                }

                if (j > 0 && i == 0) {
                    // Only ones placed: valid only if j <= limit
                    dp[i, j, 1] = (j <= limit) ? 1 : 0;
                } else if (j > 0) {
                    dp[i, j, 1] = (dp[i, j - 1, 0] + dp[i, j - 1, 1]) % MOD;
                    if (j - limit - 1 >= 0)
                        dp[i, j, 1] = (dp[i, j, 1] - dp[i, j - limit - 1, 0] + MOD) % MOD;
                }
            }
        }

        return (int)((dp[zero, one, 0] + dp[zero, one, 1]) % MOD);
    }
}