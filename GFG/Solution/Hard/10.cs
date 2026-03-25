public class Solution {
    public int overlapInt(int[][] intervals) {
        if (intervals == null || intervals.Length == 0) {
            return 0;
        }
        
        List<(int time, int delta)> events = new List<(int, int)>();
        
        foreach (var interval in intervals) {
            events.Add((interval[0], 1));
            events.Add((interval[1] + 1, -1));
        }
        
        events.Sort((a, b) => {
            if (a.time != b.time) {
                return a.time.CompareTo(b.time);
            }
            return a.delta.CompareTo(b.delta);
        });
        
        int maxOverlap = 0;
        int currentOverlap = 0;
        
        foreach (var (time, delta) in events) {
            currentOverlap += delta;
            maxOverlap = Math.Max(maxOverlap, currentOverlap);
        }
        
        return maxOverlap;
    }
}