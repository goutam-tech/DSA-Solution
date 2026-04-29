public class Solution {
    public int MinimumHammingDistance(int[] source, int[] target, int[][] allowedSwaps) {
        int n = source.Length;
        int[] parent = new int[n];
        for(int i = 0; i < n; i++) parent[i] = i;

        foreach(var swap in allowedSwaps){
            int rootA = Find(parent, swap[0]);
            int rootB = Find(parent, swap[1]);
            if(rootA != rootB) parent[rootA] = rootB;
        }

        var groups = new Dictionary<int, List<int>>();
        for(int i = 0; i < n; i++){
            int root = Find(parent, i);
            if(!groups.ContainsKey(root)) groups[root] = new List<int>();
            groups[root].Add(i);
        }

        int hamming = 0;
        foreach(var group in groups.Values){
            var sourceCount = new Dictionary<int, int>();
            foreach(int idx in group){
                int val = source[idx];
                sourceCount[val] = sourceCount.GetValueOrDefault(val, 0) + 1;
            }

            foreach(int idx in group){
                int val = target[idx];
                if(sourceCount.GetValueOrDefault(val, 0) > 0){
                    sourceCount[val]--;
                }
                else{
                    hamming++;
                }
            }
        }

        return hamming;
    }

    private int Find(int[] parent, int x){
        if(parent[x] != x) parent[x] = Find(parent, parent[x]);
        return parent[x];
    }
}