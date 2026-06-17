class Solution {
  public:
    int computeValue(int n) {
        const int MOD = 1e9 + 7;
        
        long long num = 1, den = 1;
        for (int i = 0; i < n; i++) {
            num = num * (2 * n - i) % MOD;
            den = den * (i + 1) % MOD;
        }
        
        long long inv = 1, base = den, exp = MOD - 2;
        while (exp) {
            if (exp & 1) inv = inv * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return num * inv % MOD;
    }
};