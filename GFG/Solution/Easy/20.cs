class Solution {
    public int visibleBuildings(int[] arr) {
        // code here
        int count = 1, maxHeight = arr[0];
        for(int i = 1; i < arr.Length; i++){
            if(arr[i] >= maxHeight){
                count++;
                maxHeight = arr[i];
            }
        }
        return count;
    }
}