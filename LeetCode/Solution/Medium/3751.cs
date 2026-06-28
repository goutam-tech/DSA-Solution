public class Solution {
    public int TotalWaviness(int num1, int num2) {
        return Solve(num2) - Solve(num1 - 1);
    }

    private int Solve(int n){
        if(n <= 0) return 0;
        string s = n.ToString();
        var memo = new Dictionary<long, (long count, long waveSum)>();
        var(_, total) = Dp(s, 0, -1, -1, true, false, memo);
        return (int)total; 
    }

    private (long count, long waveSum) Dp(
        string s, int pos, int prev, int prevPrev, bool tight, bool started, Dictionary<long, (long, long)> memo){
            if(pos == s.Length){
                return started ? (1, 0) : (0, 0);
            }

            long key = pos
            | ((long)(prev + 1) << 6)
            | ((long)(prevPrev + 1) << 11)
            | ((tight ? 1L : 0L) << 16)
            | ((started ? 1L : 0L) << 17);

            if(memo.TryGetValue(key, out var cached)) return cached;

            int limit = tight ? (s[pos] - '0') : 9;
            long totalCount = 0, totalWave = 0;

            for(int d = 0; d <= limit; d++){
                bool newTight = tight && (d == limit);

                if(!started && d == 0){
                    var (c, w) = Dp(s, pos + 1, -1, -1, newTight, false, memo);
                    totalCount += c;
                    totalWave += w;
                }
                else{
                    int wave = 0;
                    if(prevPrev != -1 && prev != -1){
                        if(prev > prevPrev && prev > d) wave = 1;
                        else if(prev < prevPrev && prev < d) wave = 1;
                    }

                    var (cnt, wvSum) = Dp(s, pos + 1, d, started ? prev : -1, newTight, true, memo);

                    totalCount += cnt;
                    totalWave += cnt * wave + wvSum;
                }
            }
            memo[key] = (totalCount, totalWave);
            return (totalCount, totalWave);
         }
}