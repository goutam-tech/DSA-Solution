class Solution {
    public int maxSubarrayXOR(int[] arr, int k) {
        // code here
        int n = arr.Length;
        if( n == 0 || k > n) return 0;
        
        int currentXor = 0;
        for(int i = 0; i < k; i++){
            currentXor ^= arr[i];
        }
        
        int maxXor = currentXor;
        
        for(int i = k; i < n; i++){
            currentXor ^= arr[i] ^ arr[i - k];
            maxXor = Math.Max(maxXor,currentXor);
        }
        
        return maxXor;
    }
}