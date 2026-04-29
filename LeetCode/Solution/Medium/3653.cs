public class Solution {
    public int XorAfterQueries(int[] nums, int[][] queries) {
        const int MOD = 1_000_000_007;
        int n = nums.Length;
        
        foreach (var q in queries) {
            int l = q[0], r = q[1], k = q[2];
            long v = q[3];
            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (int)(nums[idx] * v % MOD);
            }
        }
        
        int xor = 0;
        for (int i = 0; i < n; i++) {
            xor ^= nums[i];
        }
        return xor;
    }
}