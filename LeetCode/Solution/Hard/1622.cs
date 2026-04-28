namespace Hard;

public class Fancy {
    private List<long> seq = new List<long>();
    private const long MOD = 1_000_000_007;
    private long addOffset = 0;
    private long mulOffset = 1;

    public Fancy() {}

    public void Append(int val) {
        long v = ((val - addOffset) % MOD + MOD) % MOD;
        v = v * ModPow(mulOffset, MOD - 2, MOD) % MOD;
        seq.Add(v);
    }

    public void AddAll(int inc) {
        addOffset = (addOffset + inc % MOD + MOD) % MOD;
    }

    public void MultAll(int m) {
        long mm = ((long)m % MOD + MOD) % MOD;
        mulOffset = mulOffset * mm % MOD;
        addOffset = addOffset * mm % MOD;
    }

    public int GetIndex(int idx) {
        if (idx >= seq.Count) return -1;
        return (int)((seq[idx] * mulOffset % MOD + addOffset) % MOD);
    }

    private long ModPow(long b, long e, long mod) {
        long result = 1;
        b = (b % mod + mod) % mod;
        while (e > 0) {
            if ((e & 1) == 1) result = result * b % mod;
            b = b * b % mod;
            e >>= 1;
        }
        return result;
    }
}