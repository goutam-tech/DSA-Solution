public class Solution {
    public int MaxJumps(int[] arr, int d) {
        int n = arr.Length;
        int[] dp = new int[n];
        int[] indices = new int[n];

        for(int i = 0; i < n; i++){
            indices[i] = i;
        }
        Array.Sort(indices, (a, b) => arr[a].CompareTo(arr[b]));

        foreach(int i in indices){
            dp[i] = 1;
            for(int x = 1; x <= d && i + x < n; x++){
                if(arr[i + x] >= arr[i]) break;
                dp[i] = Math.Max(dp[i], 1 + dp[i + x]);
            }
            for(int x = 1; x <= d && i - x >= 0; x++){
                if(arr[i - x] >= arr[i]) break;
                dp[i] = Math.Max(dp[i], 1 + dp[i - x]);
            }
        }

        return dp.Max();
    }
}