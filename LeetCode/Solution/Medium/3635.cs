public class Solution {
    public int EarliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        int ans = int.MaxValue;
        ans = Math.Min(ans, BestFinish(landStartTime, landDuration, waterStartTime, waterDuration));
        ans = Math.Min(ans, BestFinish(waterStartTime, waterDuration, landStartTime, landDuration));
        return ans;
    }

    private int BestFinish(int[] firstStart, int[] firstDur, int[] secondStart, int[] secondDur){
        int m = secondStart.Length;
        int[] idx = new int[m];
        for(int i = 0; i < m; i++){
            idx[i] = i;
        }

        Array.Sort(idx, (a, b) => secondStart[a].CompareTo(secondStart[b]));

        int[] sortedStart = new int[m];
        int[] sortedDur = new int[m];

        for(int i = 0; i < m; i++){
            sortedStart[i] = secondStart[idx[i]];
            sortedDur[i] = secondDur[idx[i]];
        }

        int[] suffixMinSD = new int[m + 1];
        suffixMinSD[m] = int.MaxValue;
        for(int i = m - 1; i >= 0; i--){
            suffixMinSD[i] = Math.Min(suffixMinSD[i + 1], sortedStart[i]  + sortedDur[i]);
        }

        int[] prefixMinD = new int[m];
        prefixMinD[0] = sortedDur[0];
        for(int i = 1; i < m; i++){
            prefixMinD[i] = Math.Min(prefixMinD[i - 1], sortedDur[i]);
        }

        int ans = int.MaxValue;
        int n = firstStart.Length;
        for(int i = 0; i < n; i++){
            int f = Math.Max(firstStart[i], 0) + firstDur[i];

            int lo = 0, hi = m;
            while(lo < hi){
                int mid = (lo + hi) / 2;
                if(sortedStart[mid] >= f){
                    hi = mid;
                }
                else{
                    lo = mid + 1;
                }
            }
            int split = lo;

            if(split < m){
                ans = Math.Min(ans, suffixMinSD[split]);
            }

            if(split > 0){
                ans = Math.Min(ans, f + prefixMinD[split - 1]);
            }
        }
        return ans;
    }
}