namespace Hard;

public class Solution {
    public long MinimumTotalDistance(IList<int> robot, int[][] factory) {
        var robots = robot.ToList();
        robots.Sort();
        Array.Sort(factory, (a,b) => a[0].CompareTo(b[0]));

        var slots = new List<int>();
        foreach(var f in factory){
            for(int k = 0; k < f[1]; k++){
                slots.Add(f[0]);
            }
        }

        int m = robots.Count;
        int n = slots.Count;

        var dp = new long[m + 1, n + 1];
        const long INF = long.MaxValue / 2;

        for(int j = 0; j <= n; j++) dp[0, j] = 0;

        for(int i = 1; i <= m; i++) dp[i, 0] = INF;

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[i, j] = dp[i, j - 1];

                long cost = 0;
                for(int k = i; k >= 1; k--){
                    int slotIdx = j - i + k - 1;
                    if(slotIdx < 0) break;
                    cost += Math.Abs((long)robots[k - 1] - slots[slotIdx]);
                    long prev = (k - 1 == 0) ? 0 : dp[k - 1, j - i + k - 1];
                    if(prev < INF){
                        dp[i, j] = Math.Min(dp[i, j], prev + cost);
                    } 
                }
            }
        }

        return dp[m, n];
    }
}