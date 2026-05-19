class Solution {
    private Dictionary<int, int> memo = new Dictionary<int, int>();
    
    public int maxSum(int n) {
        if(n <= 0) return 0;
        if(memo.ContainsKey(n)) return memo[n];
        
        int split = maxSum(n / 2) + maxSum(n / 3) + maxSum(n / 4);
        int result = Math.Max(n, split);
        
        memo[n] = result;
        return result;
    }
}