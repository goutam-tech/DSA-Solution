class Solution {
    public List<int> search(int[] a, int[] b) {
        // code here
        var result = new List<int>();
        int n = a.Length, m = b.Length;
        if(n == 0 || m > n) return result;
        
        int[] combined = new int[n + m + 1];
        int[] lps = new int[n + m + 1];
        
        for(int i = 0; i < m; i++) combined[i] = b[i];
        combined[m] = -1;
        for(int i = 0; i < n; i++) combined[m + 1 + i] = a[i];
        
        lps[0] = 0;
        int len = 0, idx = 1;
        while(idx < combined.Length){
            if(combined[idx] == combined[len]){
                lps[idx++] = ++len;
            }
            else if(len != 0){
                len = lps[len - 1];
            }
            else{
                lps[idx++] = 0;
            }
        }
        
        for(int i = m + 1; i < combined.Length; i++){
            if(lps[i] == m){
                result.Add(i - 2 * m);
            }
        }
        
        return result;
    }
}