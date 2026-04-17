public class SegmentTree {
    public int n;
    public int[] sum, mn, mx;
    
    public SegmentTree(int n_) {
        n = n_;
        sum = new int[4 * n];
        mn = new int[4 * n];
        mx = new int[4 * n];
    }
    
    void Pull(int node) {
        
        int lc = node * 2, rc = node * 2 + 1;
        
        sum[node] = sum[lc] + sum[rc];
        mn[node] = Math.Min(mn[lc], sum[lc] + mn[rc]);
        mx[node] = Math.Max(mx[lc], sum[lc] + mx[rc]);
    }
    
    public void Update(int idx, int val) {
        Update(1, 0, n - 1, idx, val);
    }
    
    void Update(int node, int l, int r, int idx, int val) {
        
        if (l == r) {
            sum[node] = val;
            mn[node] = val;
            mx[node] = val;
            return;
        }
        
        int m = (l + r) / 2;
        if (idx <= m)
            Update(node * 2, l, m, idx, val);
        else
            Update(node * 2 + 1, m + 1, r, idx, val);
        
        Pull(node);
    }
    
    bool Exist(int node, int sum_before, int target) {
        int need = target - sum_before;
        return mn[node] <= need && need <= mx[node];
    }
    
    public int FindRightmostPrefix(int target) {
        return FindRightmostPrefix(1, 0, n - 1, 0, target);
    }
    
    int FindRightmostPrefix(int node, int l, int r, int sum_before, int target) {
        
        if (!Exist(node, sum_before, target))
            return -1;
        if (l == r)
            return l;
        
        int m = (l + r) / 2;
        int lc = node * 2, rc = node * 2 + 1;

        int sum_before_right = sum_before + sum[lc];
        if (Exist(rc, sum_before_right, target))
            return FindRightmostPrefix(rc, m + 1, r, sum_before_right, target);
        
        return FindRightmostPrefix(lc, l, m, sum_before, target);
    }
}

public class Solution {
    public int LongestBalanced(int[] nums) {
        int n = nums.Length;
        
        SegmentTree stree = new SegmentTree(n);  
        Dictionary<int, int> first = new Dictionary<int, int>();  
        
        int result = 0;
        for (int l = n - 1; l >= 0; --l) {
            int x = nums[l];
            
            if (first.ContainsKey(x)) {
                int old = first[x];
                stree.Update(old, 0);
            }
            
            first[x] = l;
            stree.Update(l, ((x & 1) == 0) ? 1 : -1); 
            
            int r = stree.FindRightmostPrefix(0);
            if (r >= l)
                result = Math.Max(result, r - l + 1);
        }
        
        return result;
    }
}