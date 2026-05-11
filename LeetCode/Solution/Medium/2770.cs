public class Solution {
    public int MaximumJumps(int[] nums, int target) {
        int n = nums.Length;
        int[] dp = new int[n];
        Array.Fill(dp, -1);
        dp[0] = 0;
        
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < j; i++) {
                if (dp[i] != -1 && Math.Abs(nums[j] - nums[i]) <= target) {
                    dp[j] = Math.Max(dp[j], dp[i] + 1);
                }
            }
        }
        
        return dp[n - 1];
    }
}