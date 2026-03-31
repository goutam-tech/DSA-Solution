public class Solution {
    public int maxProfit(int[] arr, int k) {
        // code here
        int n = arr.Length;
        if(n == 0) return 0;
        
        int hold = -arr[0];
        int cash = 0;
        
        for(int i = 1; i < n; i++){
            int prevHold = hold;
            int prevCash = cash;
            hold = Math.Max(prevHold, prevCash - arr[i]);
            cash = Math.Max(prevCash, prevHold + arr[i] - k);
        }
        
        return cash;
    }
}