class Solution {
    private long[] tree;
    private int n;
        
    private long GCD(long a, long b){
        while(b != 0) {
            long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
        
    private long LCM(long a, long b){
        if(a == 0 || b == 0) return 0;
        return (a / GCD(a, b)) * b;
    }
    
    private void Build(int[] arr, int node, int start, int end){
        if(start == end){
            tree[node] = arr[start];
        }
        else{
            int mid = (start + end) / 2;
            Build(arr, 2 * node, start, mid);
            Build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = LCM(tree[2 * node], tree[2 * node + 1]);
        }
    }
    
    private void Update(int node, int start, int end, int idx, long val){
        if(start == end){
            tree[node] = val;
        }
        else{
            int mid = (start + end) / 2;
            if(idx <= mid){
                Update(2 * node, start, mid, idx, val);
            }
            else{
                Update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = LCM(tree[2 * node], tree[2 * node + 1]);
        }
    }
    
    private long Query(int node, int start, int end, int l, int r){
        if(r < start || end < l) return 1;
        if(l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        long leftVal = Query(2 * node, start, mid, l, r);
        long rightVal = Query(2 * node + 1, mid + 1, end, l, r);
        return LCM(leftVal, rightVal);
    }
    
    public List<long> RangeLCMQuery(int[] arr, int[][] queries) {
        // code here
        n = arr.Length;
        tree = new long[4 * n];
        Build(arr, 1, 0, n - 1);
        
        var result = new List<long>();
        
        foreach(var q in queries){
            if(q[0] == 1){
                Update(1, 0, n - 1, q[1], (long)q[2]);
            }
            else{
                result.Add(Query(1, 0, n - 1, q[1], q[2]));
            }
        }
        
        return result;
    }
}