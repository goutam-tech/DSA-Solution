public class Solution
{
    public long minCost(int[] heights, int[] cost)
    {
        int n = heights.Length;
        
        var towers = new List<(int height, long cost)>();
        for (int i = 0; i < n; i++)
        {
            towers.Add((heights[i], (long)cost[i]));
        }
        towers.Sort((a, b) => a.height.CompareTo(b.height));
        
        long totalCost = 0;
        foreach (var tower in towers)
        {
            totalCost += tower.cost;
        }
        
        long halfCost = (totalCost + 1) / 2;
        long accumulatedCost = 0;
        int targetHeight = towers[0].height;
        
        foreach (var tower in towers)
        {
            accumulatedCost += tower.cost;
            if (accumulatedCost >= halfCost)
            {
                targetHeight = tower.height;
                break;
            }
        }
        
        long minCost = 0;
        for (int i = 0; i < n; i++)
        {
            minCost += (long)Math.Abs(heights[i] - targetHeight) * cost[i];
        }
        
        return minCost;
    }
}