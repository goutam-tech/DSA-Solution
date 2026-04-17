using System.Collections.Generic;

public class Solution {
    public int MinCost(int[][] grid, int k) {
        int m = grid.Length, n = grid[0].Length;
        int INF = int.MaxValue;

        int[,,] dist = new int[m, n, k + 1];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int t = 0; t <= k; t++)
                    dist[i, j, t] = INF;

        var cells = new List<(int val, int i, int j)>();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cells.Add((grid[i][j], i, j));
        cells.Sort((a, b) => a.val.CompareTo(b.val));

        int[] teleportPtr = new int[k + 1];

        var pq = new PriorityQueue<(int cost, int i, int j, int t), int>();
        dist[0, 0, 0] = 0;
        pq.Enqueue((0, 0, 0, 0), 0);

        int[][] dirs = { new[] {1,0}, new[] {0,1} };

        while (pq.Count > 0) {
            var (cost, i, j, t) = pq.Dequeue();
            if (cost > dist[i, j, t]) continue;

            if (i == m - 1 && j == n - 1)
                return cost;

            foreach (var d in dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni < m && nj < n) {
                    int newCost = cost + grid[ni][nj];
                    if (newCost < dist[ni, nj, t]) {
                        dist[ni, nj, t] = newCost;
                        pq.Enqueue((newCost, ni, nj, t), newCost);
                    }
                }
            }

            if (t < k) {
                while (teleportPtr[t] < cells.Count &&
                       cells[teleportPtr[t]].val <= grid[i][j]) {

                    var (_, x, y) = cells[teleportPtr[t]];
                    teleportPtr[t]++;

                    if (cost < dist[x, y, t + 1]) {
                        dist[x, y, t + 1] = cost;
                        pq.Enqueue((cost, x, y, t + 1), cost);
                    }
                }
            }
        }

        return -1;
    }
}