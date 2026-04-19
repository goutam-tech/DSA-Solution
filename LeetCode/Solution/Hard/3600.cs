public class Solution {
    public int MaxStability(int n, int[][] edges, int k) {
        int[] sortedStrengths = GetAllPossibleStrengths(edges);
        int lo = 0, hi = sortedStrengths.Length - 1, ans = -1;

        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(CanAchieve(n, edges, k, sortedStrengths[mid])){
                ans = sortedStrengths[mid];
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        return ans;
    }

    private int[] GetAllPossibleStrengths(int[][] edges){
        var set = new SortedSet<int>();
        foreach(var e in edges){
            set.Add(e[2]);
            set.Add(e[2] * 2);
        }
        return set.ToArray();
    }

    private bool CanAchieve(int n, int[][] edges, int k, int minStrength) {
        var mustEdges = new List<int[]>();
        var upgradeEdges = new List<int[]>();
        var normalEdges = new List<int[]>();

        foreach (var e in edges) {
            int s = e[2], must = e[3];
            if (must == 1) {
                if (s < minStrength) return false;
                mustEdges.Add(e);
            } else {
                if (s >= minStrength) normalEdges.Add(e);
                else if (s * 2 >= minStrength) upgradeEdges.Add(e);
            }
        }

        var uf = new UnionFind(n);

        foreach (var e in mustEdges)
            if (!uf.Union(e[0], e[1])) return false;

        // Pass 1: use all free edges first
        normalEdges.Sort((a, b) => b[2].CompareTo(a[2]));
        foreach (var e in normalEdges)
            uf.Union(e[0], e[1]);

        // Pass 2: use upgrade edges only if still needed
        upgradeEdges.Sort((a, b) => b[2].CompareTo(a[2]));
        int upgradesUsed = 0;
        foreach (var e in upgradeEdges) {
            if (uf.Find(e[0]) != uf.Find(e[1])) {
                if (upgradesUsed >= k) continue;
                upgradesUsed++;
                uf.Union(e[0], e[1]);
            }
        }

        return uf.Components == 1;
    }

    private class UnionFind{
        private int[] parent, rank;
        public int Components{ get; private set; }

        public UnionFind(int n){
            parent = new int[n];
            rank = new int[n];
            Components = n;
            for(int i = 0; i < n; i++) parent[i] = i;
        }

        public int Find(int x){
            int root = x;
            while(parent[root] != root) root = parent[root];
            while(parent[x] != root){
                int next = parent[x];
                parent[x] = root;
                x = next;
            }
            return root;
        }

        public bool Union(int x, int y){
            int px = Find(x), py = Find(y);
            if(px == py) return false;
            if(rank[px] < rank[py]) (px,py) = (py,px);
            parent[py] = px;
            if(rank[px] == rank[py]) rank[px]++;
            Components--;
            return true;
        }
    }
}