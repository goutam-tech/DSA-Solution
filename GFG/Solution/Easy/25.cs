class Solution {
    public bool canSplit(int[] arr) {
        // code here
        int total = 0;
        foreach(int x in arr) total += x;
        
        int left = 0;
        for(int i = 0; i < arr.Length - 1; i++){
            left += arr[i];
            if(left * 2 == total) return true;
        }
        return false;
    }
}