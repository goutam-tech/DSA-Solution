class Solution {
    public void pushZerosToEnd(int[] arr) {
        int insertPos = 0;
        
        foreach(int num in arr){
            if(num != 0){
                arr[insertPos++] = num;
            }
        }
        
        while(insertPos < arr.Length)
            arr[insertPos++] = 0;
    }
}
