class Solution {
    public int maxOnes(int[] arr) {
        int n = arr.Length;
        int totalOnes = 0;
        foreach(int x in arr) if(x == 1) totalOnes++;
        
        int maxGain = 0, currentGain = 0;
        for(int i = 0; i < n; i++){
            currentGain += arr[i] == 0 ? 1 : -1;
            if(currentGain < 0) currentGain = 0;
            if(currentGain > maxGain) maxGain = currentGain;
        }
        
        return totalOnes + maxGain;
    }
}