public class Solution {
    public int totalWays(int[] arr, int target) {
        // code here
        int n = arr.Length;
        int sum = 0;
        foreach (int x in arr) sum += x;
        
        if ((sum + target) % 2 != 0 || sum + target < 0) return 0;
        
        int s = (sum + target) / 2;
        if (s < 0) return 0;
        
        int[] dp = new int[s + 1];
        dp[0] = 1;
        
        foreach (int x in arr) {
            for (int j = s; j >= x; j--) {
                dp[j] += dp[j - x];
            }
        }
        
        return dp[s];
    }
}