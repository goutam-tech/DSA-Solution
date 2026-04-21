namespace Hard;

public class Solution {
    public int MinOperations(string s, int k) {
        int n = s.Length;
        
        if (k > n) return -1;
        
        int zeros = s.Count(c => c == '0');
        int ones = n - zeros;
        
        if (zeros == 0) return 0;

        for (int ops = 1; ops <= n * 2; ops++)
        {
            long total = (long)ops * k;
            long extra = total - zeros;
            
            if (extra < 0) continue;
            if (Math.Abs(extra % 2) == 1) continue;

            long maxZeroFlips = (long)zeros * (ops % 2 != 0 ? ops : ops - 1);
            long maxOneFlips  = (long)ones  * (ops % 2 == 0 ? ops : ops - 1);
            long maxTotal = maxZeroFlips + maxOneFlips;

            if (total <= maxTotal)
                return ops;
        }
        return -1;
    }
}