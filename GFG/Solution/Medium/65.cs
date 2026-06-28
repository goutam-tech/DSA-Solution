class Solution {
    public int countSubset(int[] arr, int k) {     
        int n = arr.Length;
        int mid = n/2;
        
        var left = new Dictionary<long,int>();
        var right = new Dictionary<long,int>();
        
        Generate(arr,0,mid,0,left);
        
        Generate(arr,mid,n,0,right);
        
        long count = 0;
        
        foreach(var kv in left){
            long need = k-kv.Key;
            if(right.ContainsKey(need)){
                count += (long)kv.Value * right[need];
            }
        }
        return  (int)count;
    }
    
    private void Generate(int[] arr,int start,int end,long sum, Dictionary<long,int> map){
        if(start == end){
            if(!map.ContainsKey(sum))
              map[sum] = 0;
            map[sum]++;
            return;
        }
        
        Generate(arr,start+1,end,sum,map);
        Generate(arr,start+1,end,sum+arr[start],map);
    }
}