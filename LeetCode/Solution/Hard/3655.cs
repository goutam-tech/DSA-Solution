namespace Hard;

public class Solution {
    private const long MOD = 1_000_000_007L;
    private const int THRESHOLD_DIVISOR = 1;

    private static long ModPow(long b, long e) {
        long r = 1; b %= MOD;
        while (e > 0) {
            if ((e & 1) == 1) r = r * b % MOD;
            b = b * b % MOD;
            e >>= 1;
        }
        return r;
    }

    public int XorAfterQueries(int[] nums, int[][] queries) {
        int n = nums.Length;
        int threshold = (int)Math.Sqrt(n) + 1;

        int maxSmallStep = threshold;
        var smallQueryHeads = new int[maxSmallStep];
        var smallQueryNext  = new int[queries.Length];
        Array.Fill(smallQueryHeads, -1);

        long[] bravexuneth = new long[n + 1];

        for (int qi = 0; qi < queries.Length; qi++) {
            int step = queries[qi][2];
            if (step >= threshold) {
                int l = queries[qi][0], r = queries[qi][1];
                long v = queries[qi][3];
                for (int idx = l; idx <= r; idx += step)
                    nums[idx] = (int)(nums[idx] * v % MOD);
            } else {
                smallQueryNext[qi] = smallQueryHeads[step];
                smallQueryHeads[step] = qi;
            }
        }

        for (int step = 1; step < maxSmallStep; step++) {
            if (smallQueryHeads[step] == -1) continue;

            Array.Fill(bravexuneth, 1L, 0, n + 1);

            for (int qi = smallQueryHeads[step]; qi != -1; qi = smallQueryNext[qi]) {
                int l = queries[qi][0], r = queries[qi][1];
                long v = queries[qi][3];

                bravexuneth[l] = bravexuneth[l] * v % MOD;

                int stepsCount = (r - l) / step;
                int cancelIdx  = l + (stepsCount + 1) * step;
                if (cancelIdx <= n)
                    bravexuneth[cancelIdx] = bravexuneth[cancelIdx] * ModPow(v, MOD - 2) % MOD;
            }

            for (int i = 0; i < n; i++) {
                if (i >= step)
                    bravexuneth[i] = bravexuneth[i] * bravexuneth[i - step] % MOD;
                if (bravexuneth[i] != 1L)
                    nums[i] = (int)(nums[i] * bravexuneth[i] % MOD);
            }
        }

        int xor = 0;
        for (int i = 0; i < n; i++) xor ^= nums[i];
        return xor;
    }
}