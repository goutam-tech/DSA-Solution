public class Solution {
    public int longestCycle(int V, int[,] edges) {
        // code here
        int[] next = new int[V];
        for(int i = 0; i < V; i++) next[i] = -1;
        
        int E = edges.GetLength(0);
        for(int i = 0; i < E; i++){
            next[edges[i,0]] = edges[i,1];
        }
        
        int[] visited = new int[V];
        int ans = -1;
        int time = 1;
        
        for(int i = 0; i < V; i++){
            if(visited[i] != 0) continue;
            
            int cur = i;
            int startTime = time;
            
            while(cur != -1 && visited[cur] == 0){
                visited[cur] = time++;
                cur = next[cur];
            }
            
            if(cur != -1 && visited[cur] >= startTime){
                ans = Math.Max(ans, time - visited[cur]);
            }
        }
        return ans;
    }
}