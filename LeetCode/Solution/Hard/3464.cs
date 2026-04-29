namespace Hard;

public class Solution {
    public int MaxDistance(int side, int[][] points, int k) {
         long[] t = new long[points.Length];
        int n = points.Length;

        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            if (y == 0) t[i] = x;
            else if (x == side) t[i] = (long)side + y;
            else if (y == side) t[i] = 3L * side - x;
            else t[i] = 4L * side - y;
        }

        Array.Sort(t);
        long perimeter = 4L * side;

        bool CanAchieve(long minDist) {
            for (int start = 0; start < n; start++) {
                int count = 1;
                long first = t[start];
                long prev = first;
                bool ok = false;

                for (int step = 1; step < k; step++) {
                    long target = prev + minDist;
                    int lo = 0, hi = n - 1, found = -1;

                    if (target <= t[n - 1]) {
                        lo = 0; hi = n - 1;
                        while (lo <= hi) {
                            int mid = (lo + hi) / 2;
                            if (t[mid] >= target) { found = mid; hi = mid - 1; }
                            else lo = mid + 1;
                        }
                    }

                    if (found == -1) {
                        long wrapped = target - perimeter;
                        lo = 0; hi = n - 1;
                        while (lo <= hi) {
                            int mid = (lo + hi) / 2;
                            if (t[mid] >= wrapped) { found = mid; hi = mid - 1; }
                            else lo = mid + 1;
                        }
                        if (found == -1 || found == start) break;
                        prev = t[found] + perimeter;
                    } else {
                        if (found == start) break;
                        prev = t[found];
                    }
                    count++;
                }

                if (count == k) {
                    long lastToFirst = first + perimeter - prev;
                    if (lastToFirst >= minDist) return true;
                }
            }
            return false;
        }

        long lo = 1, hi = 2L * side, ans = 0;
        while (lo <= hi) {
            long mid = (lo + hi) / 2;
            if (CanAchieve(mid)) { ans = mid; lo = mid + 1; }
            else hi = mid - 1;
        }

        return (int)ans;
    }
}