public class Solution {
    public int countWays(int n, int k) {
        if (n == 0) return 0;
        if (n == 1) return k;
        if (n == 2) return k * k;

        long same = k;
        long diff = (long)k * (k - 1);

        for (int i = 3; i <= n; i++) {
            long newSame = diff;
            long newDiff = (same + diff) * (k - 1);
            same = newSame;
            diff = newDiff;
        }

        return (int)(same + diff);
    }
}