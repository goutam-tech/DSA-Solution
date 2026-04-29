public class Solution {
    public int ConcatenatedBinary(int n) {
        long result = 0;
        long mod = 1_000_000_007;

        for(int i = 1; i <= n; i++){
            int bits = (int)Math.Floor(Math.Log2(i)) + 1;

            result = ((result << bits) | i) % mod;
        }

        return (int)result;
    }
}