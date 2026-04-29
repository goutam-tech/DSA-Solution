using System;

namespace Hard;

public class Solution {
    const long MOD = 1000000007;

    long Pow(long a, long b) {
        long res = 1 % MOD;
        a %= MOD;
        while (b > 0) {
            if ((b & 1) == 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    public int SumOfNumbers(int l, int r, int k) {
        long d = r - l + 1;
        long sumDigits = (long)(l + r) * d / 2 % MOD;
        long pow = Pow(d, k - 1);
        long geo = (Pow(10, k) - 1 + MOD) % MOD * Pow(9, MOD - 2) % MOD;
        long ans = sumDigits * pow % MOD * geo % MOD;
        return (int)ans;
    }
}