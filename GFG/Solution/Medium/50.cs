class Solution {
    public long subarrayXor(int[] arr, int k) {
        Dictionary<int, int> prefixCount = new Dictionary<int, int>();
        prefixCount[0] = 1;
        
        int count = 0;
        int perfixXor = 0;
        
        foreach(int num in arr){
            perfixXor ^= num;
            
            int needed = perfixXor ^ k;
            
            if(prefixCount.ContainsKey(needed))
              count += prefixCount[needed];
              
            if(prefixCount.ContainsKey(perfixXor))
               prefixCount[perfixXor]++;
            else
              prefixCount[perfixXor] = 1;
        }
        
        return count;
    }
}