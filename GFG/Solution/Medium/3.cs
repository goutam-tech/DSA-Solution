class Solution {
    public int minCost(int[,] houses) {
        int n = houses.GetLength(0);
        if (n <= 1) return 0;
        
        int[] minDist = new int[n];
        bool[] inMST = new bool[n];
        
        for (int i = 0; i < n; i++) minDist[i] = int.MaxValue;
        minDist[0] = 0;
        
        int totalCost = 0;
        
        for (int iter = 0; iter < n; iter++) {
            int u = -1;
            for (int i = 0; i < n; i++) {
                if (!inMST[i] && (u == -1 || minDist[i] < minDist[u]))
                    u = i;
            }
            
            inMST[u] = true;
            totalCost += minDist[u];
            
            for (int v = 0; v < n; v++) {
                if (!inMST[v]) {
                    int dist = Math.Abs(houses[u, 0] - houses[v, 0]) + Math.Abs(houses[u, 1] - houses[v, 1]);
                    if (dist < minDist[v])
                        minDist[v] = dist;
                }
            }
        }
        
        return totalCost;
    }
}