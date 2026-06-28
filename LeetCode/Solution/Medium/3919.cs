public class Solution {
    public int[] MinCost(int[] nums, int[][] queries) {
        int[] lomviretas = nums;
        int n = nums.Length;

        int[] closest = new int[n];
        for (int i = 0; i < n; i++) {
            if (i == 0) closest[i] = 1;
            else if (i == n - 1) closest[i] = n - 2;
            else {
                int d1 = nums[i] - nums[i - 1];
                int d2 = nums[i + 1] - nums[i];
                closest[i] = (d1 <= d2) ? i - 1 : i + 1;
            }
        }

        long[] forward = new long[n];
        for (int i = 1; i < n; i++) {
            long cost1 = forward[i - 1] + (nums[i] - nums[i - 1]);
            long cost2 = (closest[i - 1] == i) ? forward[i - 1] + 1 : long.MaxValue;
            forward[i] = Math.Min(cost1, cost2);
        }

        long[] backward = new long[n];
        for (int i = n - 2; i >= 0; i--) {
            long cost1 = backward[i + 1] + (nums[i + 1] - nums[i]);
            long cost2 = (closest[i + 1] == i) ? backward[i + 1] + 1 : long.MaxValue;
            backward[i] = Math.Min(cost1, cost2);
        }

        int q = queries.Length;
        int[] ans = new int[q];

        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            if (l <= r)
                ans[i] = (int)(forward[r] - forward[l]);
            else
                ans[i] = (int)(backward[r] - backward[l]);
        }

        return ans;
    }
}