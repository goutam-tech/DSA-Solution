public class Solution {
    public int[][] MinAbsDiff(int[][] grid, int k) {
        int m = grid.Length, n = grid[0].Length;
        int rows = m - k + 1, cols = n - k + 1;
        int[][] ans = new int[rows][];
        for (int i = 0; i < rows; i++) ans[i] = new int[cols];

        var colSets = new SortedDictionary<int, int>[n];
        for (int c = 0; c < n; c++) colSets[c] = new SortedDictionary<int, int>();

        for (int r = 0; r < k; r++)
            for (int c = 0; c < n; c++)
                AddToDict(colSets[c], grid[r][c]);

        var window = new SortedDictionary<int, int>();

        for (int i = 0; i < rows; i++) {
            window.Clear();
            for (int c = 0; c < k; c++)
                foreach (var kv in colSets[c])
                    AddToDict(window, kv.Key, kv.Value);

            for (int j = 0; j < cols; j++) {
                ans[i][j] = MinDiffInDict(window);

                if (j + 1 < cols) {
                    foreach (var kv in colSets[j])
                        RemoveFromDict(window, kv.Key, kv.Value);
                    foreach (var kv in colSets[j + k])
                        AddToDict(window, kv.Key, kv.Value);
                }
            }

            if (i + 1 < rows) {
                for (int c = 0; c < n; c++) {
                    RemoveFromDict(colSets[c], grid[i][c]);
                    AddToDict(colSets[c], grid[i + k][c]);
                }
            }
        }

        return ans;
    }

    private int MinDiffInDict(SortedDictionary<int, int> dict) {
        if (dict.Count <= 1) return 0;
        int minDiff = int.MaxValue;
        int prev = int.MinValue;
        foreach (var key in dict.Keys) {
            if (prev != int.MinValue)
                minDiff = Math.Min(minDiff, key - prev);
            if (minDiff == 0) return 0;
            prev = key;
        }
        return minDiff == int.MaxValue ? 0 : minDiff;
    }

    private void AddToDict(SortedDictionary<int, int> dict, int val, int cnt = 1) {
        if (dict.TryGetValue(val, out int c)) dict[val] = c + cnt;
        else dict[val] = cnt;
    }

    private void RemoveFromDict(SortedDictionary<int, int> dict, int val, int cnt = 1) {
        if (!dict.TryGetValue(val, out int c)) return;
        if (c <= cnt) dict.Remove(val);
        else dict[val] = c - cnt;
    }
}