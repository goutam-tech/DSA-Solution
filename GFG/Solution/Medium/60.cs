class Solution {
    public int maxOnes(int[] arr, int k) {
        int left = 0;
        int zeroCount = 0;
        int maxLen = 0;
        
        for(int right = 0; right<arr.Length; right++){
            if(arr[right] == 0)
              zeroCount++;
              
            while(zeroCount > k){
                if(arr[left] == 0)
                  zeroCount--;
                  
                left++;
            }
            
            maxLen = Math.Max(maxLen, right-left+1);
        }
        
        return maxLen;
    }
}