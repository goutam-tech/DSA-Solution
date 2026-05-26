class Solution {
    public int minSteps(int[] arr, int start, int end) {
        
        if(start == end) return 0;
        
        Queue<(int val, int steps)> queue = new Queue<(int, int)>();
        HashSet<int> visited = new HashSet<int>();
        
        queue.Enqueue((start, 0));
        visited.Add(start);
        
        while(queue.Count > 0){
            var (current, steps) = queue.Dequeue();
            
            foreach(int num in arr){
                int next = (current * num) % 1000;
                
                if(next == end) return steps + 1;
                
                if(!visited.Contains(next)){
                    visited.Add(next);
                    queue.Enqueue((next, steps + 1));
                }
            }
        }
        
        return -1;
    }
}