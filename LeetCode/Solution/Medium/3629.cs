public class Solution {
    public int MinJumps(int[] nums) {
        int n = nums.Length;
        if(n == 1) return 0;

        var primeToIndices = new Dictionary<int, List<int>>();

        for(int i = 0; i < n; i++){
            foreach(int p in GetPrimeFactors(nums[i])){
                if(!primeToIndices.ContainsKey(p)){
                    primeToIndices[p] = new List<int>();
                }
                primeToIndices[p].Add(i);
            }
        }

        var visited = new bool[n];
        visited[0] = true;
        var queue = new Queue<int>();
        queue.Enqueue(0);
        int steps = 0;

        while(queue.Count > 0){
            steps++;
            int size = queue.Count;
            while(size-- > 0){
                int cur = queue.Dequeue();

                int[] neighbors = { cur - 1, cur + 1 };
                foreach(int nb in neighbors){
                    if(nb < 0 || nb >= n || visited[nb]) continue;
                    if(nb == n - 1) return steps;
                    visited[nb] = true;
                    queue.Enqueue(nb);
                }

                foreach(int p in GetPrimeFactors(nums[cur])){
                    if(nums[cur] != p) continue;
                    
                    if(!primeToIndices.ContainsKey(p)) continue;

                    foreach(int j in primeToIndices[p]){
                        if(visited[j]) continue;
                        if(j == n - 1) return steps;
                        visited[j] = true;
                        queue.Enqueue(j);
                    }
                    primeToIndices.Remove(p);
                }
            }
        }

        return -1;
    }

    private List<int> GetPrimeFactors(int val){
        var factors = new List<int>();
        for(int f = 2; (long)f * f <= val; f++){
            if(val % f == 0){
                factors.Add(f);
                while(val % f == 0) val /= f;
            }
        }

        if(val > 1) factors.Add(val);
        return factors;
    }
}