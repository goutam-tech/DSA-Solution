public class Solution {
    public long MinimumCost(string source, string target, char[] original, char[] changed, int[] cost) {
        const int INF = int.MaxValue / 2;
        int n = 26;

        int[,] dist = new int[n,n];

        for(int i=0;i<n;i++){
            for(int j=0; j<n;j++){
                dist[i,j] = (i==j) ? 0 : INF;
            }
        }

        for(int i=0;i<original.Length;i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u,v] = Math.Min(dist[u,v],cost[i]);
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i,k] + dist[k,j] < dist[i,j]){
                        dist[i,j] = dist[i,k]+dist[k,j];
                    }
                }
            }
        }

        long totalCost = 0;
        
        for(int i=0;i<source.Length;i++){
            int s = source[i] - 'a';
            int t = target[i] - 'a';

            if(dist[s,t] == INF){
                return -1;
            }

            totalCost += dist[s,t];
        }
        return totalCost;
    }
}