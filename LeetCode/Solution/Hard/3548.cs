namespace Hard;

public class Solution {
    public bool CanPartitionGrid(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;

        long total = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                total += grid[i][j];

        var posMap = new Dictionary<long, List<(int r, int c)>>();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                long v = grid[i][j];
                if (!posMap.ContainsKey(v)) posMap[v] = new List<(int,int)>();
                posMap[v].Add((i, j));
            }

        long topSum = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) topSum += grid[i][j];
            long botSum = total - topSum;
            int topRows = i + 1, botRows = m - i - 1;

            if (topSum == botSum) return true;

            long diff = topSum - botSum;
            if (diff > 0) {
                if (CanRemove(posMap, diff, 0, i, 0, n - 1, topRows, n)) return true;
            } else {
                diff = -diff;
                if (CanRemove(posMap, diff, i + 1, m - 1, 0, n - 1, botRows, n)) return true;
            }
        }

        long leftSum = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) leftSum += grid[i][j];
            long rightSum = total - leftSum;
            int leftCols = j + 1, rightCols = n - j - 1;

            if (leftSum == rightSum) return true;

            long diff = leftSum - rightSum;
            if (diff > 0) {
                if (CanRemove(posMap, diff, 0, m - 1, 0, j, m, leftCols)) return true;
            } else {
                diff = -diff;
                if (CanRemove(posMap, diff, 0, m - 1, j + 1, n - 1, m, rightCols)) return true;
            }
        }

        return false;
    }

    private bool CanRemove(Dictionary<long, List<(int r, int c)>> posMap, long diff,
        int r1, int r2, int c1, int c2, int sRows, int sCols) {

        if (sRows * sCols == 1) return false;

        if (!posMap.ContainsKey(diff)) return false;

        if (sRows >= 2 && sCols >= 2) {
            foreach (var (r, c) in posMap[diff])
                if (r >= r1 && r <= r2 && c >= c1 && c <= c2) return true;
            return false;
        }

        if (sRows == 1) {
            foreach (var (r, c) in posMap[diff])
                if (r == r1 && (c == c1 || c == c2)) return true;
            return false;
        }

        if (sCols == 1) {
            foreach (var (r, c) in posMap[diff])
                if (c == c1 && (r == r1 || r == r2)) return true;
            return false;
        }

        return false;
    }
}