class Solution {
    public int equalSumSpan(int[] a1, int[] a2) {
        int n = a1.Length;
        var firstOccurrence = new Dictionary<int,int>();
        firstOccurrence[0] = -1;
        
        int perfixSum = 0;
        int maxLen = 0;
        
        for(int i = 0; i < n; i++){
            perfixSum += (a1[i] - a2[i]);
            
            if(firstOccurrence.ContainsKey(perfixSum)){
                maxLen = Math.Max(maxLen, i-firstOccurrence[perfixSum]);
            }
            else{
                firstOccurrence[perfixSum] = i;
            }
        }
        
        return maxLen;
    }
}