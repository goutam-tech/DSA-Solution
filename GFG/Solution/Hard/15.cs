class Solution {
    public List<int> countBSTs(int[] arr) {
        // code here
        int n = arr.Length;
        int[] catalan = PrecomputeCatalan(n);
        
        int[] original = (int[])arr.Clone();
        
        Array.Sort(arr);
        int[] sorted = arr;
        
        var rankMap = new Dictionary<int, int>();
        for(int i = 0; i < n; i++){
            rankMap[sorted[i]] = i;
        }
        
        Array.Sort(arr);
        
        List<int> result = new List<int>();
        foreach(int val in original){
            int rank = rankMap[val];
            int left = rank;
            int right = n - rank - 1;
            result.Add(catalan[left] * catalan[right]);
        }
        
        return result;
    }
    
    private int[] PrecomputeCatalan(int n){
        int[] cat = new int[n + 1];
        cat[0] = 1;
        cat[1] = 1;
        for(int i = 2; i <= n; i++){
            cat[i] = 0;
            for(int j = 0; j < i; j++){
                cat[i] += cat[j] * cat[i - 1 -j];
            }
        }
        return cat;
    }
}
