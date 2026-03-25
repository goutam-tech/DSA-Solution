class Solution {
    public static int kBitFlips(int[] arr, int k) {
        int n = arr.Length;
        int[] flipped = new int[n];
        int flips = 0, result = 0;
        
        for(int i = 0; i < n; i++){
            if(i >= k) flips ^= flipped[i - k];
            
            if((arr[i] ^ flips) == 0){
                if(i + k > n) return -1;
                
                flips ^= 1;
                flipped[i] = 1;
                result++;
            }
        }
        
        return result;
    }
}