class Solution {
    public int maxSubarraySum(int[] arr) {
        int maxNum = arr[0];
        int currentNum = arr[0];
        
        for(int i = 1; i < arr.Length; i++){
            currentNum = Math.Max(arr[i], currentNum + arr[i]);
            maxNum = Math.Max(maxNum, currentNum);
        }
        
        return maxNum;
    }
}