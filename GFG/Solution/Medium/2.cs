public class Solution {
    public int countPartitions(int[] arr, int diff) {
        int n = arr.Length;
        int totalSum = 0;
        foreach (int x in arr) totalSum += x;
        
        if ((totalSum + diff) % 2 != 0) return 0;
        if (totalSum + diff < 0) return 0;
        
        int target = (totalSum + diff) / 2;
        
        if (target < 0) return 0;
        
        long MOD = 1000000007L;
        long[] dp = new long[target + 1];
        dp[0] = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = target; j >= arr[i]; j--) {
                dp[j] = (dp[j] + dp[j - arr[i]]) % MOD;
            }
        }
        
        return (int)dp[target];
    }
}