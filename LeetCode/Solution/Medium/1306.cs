public class Solution {
    public bool CanReach(int[] arr, int start) {
        if(arr[start] == 0) return true;

        var queue = new Queue<int>();
        queue.Enqueue(start);

        var visited = new bool[arr.Length];
        visited[start] = true;

        while(queue.Count > 0){
            int i = queue.Dequeue();

            int[] nextPositions = { i + arr[i], i - arr[i] };

            foreach(int next in nextPositions){
                if(next >= 0 && next < arr.Length && ! visited[next]){
                    if(arr[next] == 0) return true;
                    visited[next] = true;
                    queue.Enqueue(next);
                }
            }
        }

        return false;
    }
}