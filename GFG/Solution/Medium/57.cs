class Solution {
    public int maxProduct(int[] arr) {
        int maxEndingHere = arr[0];
        int minEndingHere = arr[0];
        int result = arr[0];
        
        for(int i=1;i<arr.Length;i++){
            int curr = arr[i];
            
            if(curr < 0){
                int temp = maxEndingHere;
                maxEndingHere = minEndingHere;
                minEndingHere = temp;
            }
            
            maxEndingHere = Math.Max(curr,curr*maxEndingHere);
            minEndingHere = Math.Min(curr,curr*minEndingHere);
            
            
            result = Math.Max(result , maxEndingHere);
        }
        
        return result;
    }
}