class Solution {
    public List<int> freqInRange(int[] arr, int[][] queries) {
        // code here
        var posMap = new Dictionary<int, List<int>>();
        
        for(int i = 0; i < arr.Length; i++){
            if(!posMap.ContainsKey(arr[i])){
                posMap[arr[i]] = new List<int>();
            }
            posMap[arr[i]].Add(i);
        }
        
        var result = new List<int>(queries.Length);
        
        foreach(var q in queries){
            int l = q[0], r = q[1], x = q[2];
            
            if(!posMap.TryGetValue(x, out var positions)){
                result.Add(0);
                continue;
            }
            
            int lo = LowerBound(positions, l);
            int hi = UpperBound(positions, r);
            result.Add(hi - lo);
        }
        
        return result;
    }
    
    private int LowerBound(List<int> list, int target){
        int lo = 0, hi = list.Count;
        while(lo < hi){
            int mid = (lo + hi) >> 1;
            if(list[mid] < target){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }
        return lo;
    }
    
    private int UpperBound(List<int> list, int target){
        int lo = 0, hi = list.Count;
        while(lo < hi){
            int mid = (lo + hi) >> 1;
            if(list[mid] <= target){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }
        return lo;
    }
}