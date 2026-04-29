public class Solution {
    public long MinNumberOfSeconds(int mountainHeight, int[] workerTimes) {
        long lo = 0, hi = (long)workerTimes.Max() * mountainHeight * (mountainHeight + 1) / 2;

        while(lo < hi){
            long mid = lo + (hi - lo) / 2;
            if(CanFinish(mid, mountainHeight, workerTimes))
              hi = mid;
            else
              lo = mid + 1;
        }
        return lo;
    }

    private bool CanFinish(long time, int mountainHeight, int[] workerTimes){
        int totalReduction = 0;
        foreach(int wt in workerTimes){
            long x = (long)((Math.Sqrt(1+8.0 * time / wt) - 1) / 2);
            totalReduction += (int)Math.Min(x, mountainHeight);
            if(totalReduction >= mountainHeight) return true;
        }
        return totalReduction >= mountainHeight;
    }
}