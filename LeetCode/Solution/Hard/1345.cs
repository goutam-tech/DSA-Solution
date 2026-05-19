public class Solution {
    public int MinJumps(int[] arr) {
        int n = arr.Length;
        if(n == 1) return 0;

        var graph = new Dictionary<int, List<int>>();
        for(int i = 0; i < n; i++){
            if(!graph.ContainsKey(arr[i])){
                graph[arr[i]] = new List<int>();
            }
            graph[arr[i]].Add(i);
        }

        var visited = new bool[n];
        var queue = new Queue<int>();
        queue.Enqueue(0);
        visited[0] = true;
        int steps = 0;

        while(queue.Count > 0){
            int size = queue.Count;
            steps++;
            while (size-- > 0) {
                int i = queue.Dequeue();
                
                int[] neighbors = new int[] { i - 1, i + 1 };
                foreach (int nb in neighbors) {
                    if (nb >= 0 && nb < n && !visited[nb]) {
                        if (nb == n - 1) return steps;
                        visited[nb] = true;
                        queue.Enqueue(nb);
                    }
                }
                
                if (graph.ContainsKey(arr[i])) {
                    foreach (int j in graph[arr[i]]) {
                        if (!visited[j]) {
                            if (j == n - 1) return steps;
                            visited[j] = true;
                            queue.Enqueue(j);
                        }
                    }
                    graph.Remove(arr[i]);
                }
            }
        }

        return -1;
    }
}