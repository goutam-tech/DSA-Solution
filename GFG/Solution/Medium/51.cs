class Solution {
    public int hIndex(int[] citations) {
        if(citations == null || citations.Length == 0)
          return 0;
          
        Array.Sort(citations, (a,b) => b.CompareTo(a));
        
        int h = 0;
        for(int i = 0; i < citations.Length; i++){
            if(citations[i] >= i+1){
                h = i + 1;
            }
            else
                break;
        }
        
        return h;
    }
}