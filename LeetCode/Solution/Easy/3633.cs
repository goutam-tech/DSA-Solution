public class Solution {
    public int EarliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        int L = landStartTime.Length, W = waterStartTime.Length;

        int[][] land = new int[L][];
        for(int i = 0; i < L; i++){
            land[i] = new int[]{
                landStartTime[i], landDuration[i]
            };
        }
        Array.Sort(land, (a, b) => a[0].CompareTo(b[0]));

        int[][] water = new int[W][];
        for(int i = 0; i < W; i++){
            water[i] = new int[]{
                waterStartTime[i], waterDuration[i]
            };
        }
        Array.Sort(water, (a, b) => a[0].CompareTo(b[0]));

        int[] prefMinWaterDur = new int[W];
        prefMinWaterDur[0] = water[0][1];
        for (int i = 1; i < W; i++){
            prefMinWaterDur[i] = Math.Min(prefMinWaterDur[i-1], water[i][1]);
        }
        
        int[] sufMinWaterFinish = new int[W];
        sufMinWaterFinish[W-1] = water[W-1][0] + water[W-1][1];
        for (int i = W-2; i >= 0; i--){
            sufMinWaterFinish[i] = Math.Min(sufMinWaterFinish[i+1], water[i][0] + water[i][1]);
        }       

        int[] prefMinLandDur = new int[L];
        prefMinLandDur[0] = land[0][1];
        for (int i = 1; i < L; i++){
            prefMinLandDur[i] = Math.Min(prefMinLandDur[i-1], land[i][1]);
        }
        
        int[] sufMinLandFinish = new int[L];
        sufMinLandFinish[L-1] = land[L-1][0] + land[L-1][1];
        for (int i = L-2; i >= 0; i--){
            sufMinLandFinish[i] = Math.Min(sufMinLandFinish[i+1], land[i][0] + land[i][1]);
        }
        
        int ans = int.MaxValue;
        for (int i = 0; i < L; i++) {
            int lf = land[i][0] + land[i][1];
            int lo = 0, hi = W;
            while (lo < hi) { 
                int mid = (lo+hi)/2; 
                if (water[mid][0] >= lf) 
                    hi = mid; 
                else 
                    lo = mid+1; 
            }
            if (lo < W) 
                ans = Math.Min(ans, sufMinWaterFinish[lo]);
            if (lo > 0) 
                ans = Math.Min(ans, lf + prefMinWaterDur[lo-1]);
        }
        
        for (int j = 0; j < W; j++) {
            int wf = water[j][0] + water[j][1];
            int lo = 0, hi = L;
            while (lo < hi) { 
                int mid = (lo+hi)/2; 
                if (land[mid][0] >= wf) 
                    hi = mid; 
                else 
                    lo = mid+1; 
            }
            if (lo < L) 
                ans = Math.Min(ans, sufMinLandFinish[lo]);
            if (lo > 0) 
                ans = Math.Min(ans, wf + prefMinLandDur[lo-1]);
        }
        
        return ans;
    }
}