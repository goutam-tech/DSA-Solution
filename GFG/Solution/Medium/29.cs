class Solution {
    public void nextPermutation(int[] arr) {
        // code here
        int n = arr.Length;
        int pivot = -1;
        
        for(int i = n - 2; i >= 0; i--){
            if(arr[i] < arr[i + 1]){
                pivot = i;
                break;
            }
        }
        
        if(pivot == -1){
            Reverse(arr, 0, n - 1);
            return;
        }
        
        for(int i = n - 1; i > pivot; i--){
            if(arr[i] > arr[pivot]){
                Swap(arr, i, pivot);
                break;
            }
        }
        
        Reverse(arr, pivot + 1, n - 1);
    }
    
    private void Reverse(int[] arr, int left, int right){
        while(left < right){
            Swap(arr, left++, right--);
        }
    }
    
    private void Swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}