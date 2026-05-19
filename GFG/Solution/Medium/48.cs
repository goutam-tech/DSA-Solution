class Solution {
    public void sort012(int[] arr) {
        int low = 0, mid = 0, high = arr.Length - 1;
        
        while(mid <= high){
            if(arr[mid] == 0){
                Swap(arr,low,mid);
                low++;
                mid++;
            }
            else if(arr[mid] == 1){
                mid++;
            }
            else{
                Swap(arr,mid,high);
                high--;
            }
        }
    }
    
    private void Swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}