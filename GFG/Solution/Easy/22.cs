class Solution {
    public int GetSecondLargest(int[] arr) {
        int n = arr.Length;
        if(n < 2) return -1;
        
        Array.Sort(arr);
        
        for(int i = n - 2; i >= 0; i--){
            if(arr[i] < arr[n-1])
              return arr[i];
        }
        
        return -1;
    }
}