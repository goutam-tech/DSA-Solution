public class Solution {
    public long MaxSumTrionic(int[] nums) {
        int n = nums.Length;
        if (n < 4) return long.MinValue;

        long inc1 = long.MinValue;
        long dec  = long.MinValue;
        long inc2 = long.MinValue;
        long ans  = long.MinValue;

        for (int i = 1; i < n; i++) {
            long a = nums[i - 1];
            long b = nums[i];

            long prevInc1 = inc1;
            long prevDec  = dec;
            long prevInc2 = inc2;

            if (b > a) {
                // increasing
                inc1 = (prevInc1 == long.MinValue)
                    ? a + b
                    : Math.Max(prevInc1 + b, a + b);

                // third phase
                inc2 = long.MinValue;
                if (prevDec != long.MinValue)
                    inc2 = prevDec + b;
                if (prevInc2 != long.MinValue)
                    inc2 = Math.Max(inc2, prevInc2 + b);

                if (inc2 != long.MinValue)
                    ans = Math.Max(ans, inc2);

                // dec cannot continue on increase
                dec = long.MinValue;
            }
            else if (b < a) {
                // decreasing
                dec = long.MinValue;
                if (prevInc1 != long.MinValue)
                    dec = prevInc1 + b;
                if (prevDec != long.MinValue)
                    dec = Math.Max(dec, prevDec + b);

                // inc phases cannot continue
                inc1 = long.MinValue;
                inc2 = long.MinValue;
            }
            else {
                // equal breaks strictness
                inc1 = dec = inc2 = long.MinValue;
            }
        }

        return ans;
    }
}