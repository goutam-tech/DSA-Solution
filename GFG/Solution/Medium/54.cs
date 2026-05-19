class Solution {
    public long InversionCount(int[] arr) {
        int n = arr.Length;
        int[] temp = new int[n];
        return MergeSort(arr, temp, 0, n-1);
    }
    
    private static long MergeSort(int[] arr, int[] temp, int left, int right){
        long inCount = 0;
        if(left < right){
            int mid = (left + right) / 2;
            
            inCount += MergeSort(arr,temp,left,mid);
            inCount += MergeSort(arr,temp,mid+1,right);
            inCount += Merge(arr,temp,left,mid,right);
        }
        
        return inCount;
    }
    
    private static long Merge(int[] arr, int[] temp, int left, int mid, int right){
        int i = left;
        int j = mid + 1;
        int k = left;
        long inCount = 0;
        
        while(i <= mid && j <= right){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                inCount += (mid - i + 1);
                temp[k++] = arr[j++];
            }
        }
        
        while(i <= mid){
            temp[k++] = arr[i++];
        }
        
        while(j <= right){
            temp[k++] = arr[j++];
        }
        
        for(int idx = left; idx <= right; idx++){
            arr[idx] = temp[idx];
        }
        return inCount;
    }
}