class Solution {
    public void RotateArr(int[] arr, int d) {
        // Code Here
        int n = arr.Length;
        if(n == 0) return;
        
        d = d % n;
        if(d == 0) return;
        
        Reverse(arr, 0, d - 1);
        Reverse(arr, d, n - 1);
        Reverse(arr, 0, n - 1);
    }
    
    private void Reverse(int[] arr, int left, int right){
        while(left < right){
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            
            left++;
            right--;
        }
    }
}