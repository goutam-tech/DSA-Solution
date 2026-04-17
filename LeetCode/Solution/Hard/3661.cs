public class Solution {
    const int NEG = int.MinValue / 2;
    int[] s1, s2;
    int M;

    public int MaxWalls(int[] robots, int[] distance, int[] walls) {
        int n = robots.Length;
        M = walls.Length;
        if (M == 0) return 0;

        int[] sw = (int[])walls.Clone();
        Array.Sort(sw);

        int[] ord = Enumerable.Range(0, n).ToArray();
        Array.Sort(ord, (a, b) => robots[a].CompareTo(robots[b]));
        int[] sr = new int[n], sd = new int[n];
        for (int i = 0; i < n; i++) { sr[i] = robots[ord[i]]; sd[i] = distance[ord[i]]; }

        s1 = new int[4 * M]; Array.Fill(s1, NEG);
        s2 = new int[4 * M]; Array.Fill(s2, NEG);

        for (int i = 0; i < n; i++) {
            int pos = sr[i], d = sd[i];

            int leftMin = i > 0 ? Math.Max(pos - d, sr[i-1] + 1) : pos - d;
            int ll = LB(sw, leftMin), rl = UB(sw, pos) - 1;

            int rightMax = i < n-1 ? Math.Min(pos + d, sr[i+1] - 1) : pos + d;
            int lr = LB(sw, pos), rr = UB(sw, rightMax) - 1;

            int newAtRl = ll <= rl ? Best(ll, rl) : NEG;
            int newAtRr = lr <= rr ? Best(lr, rr) : NEG;

            if (ll <= rl && lr <= rr && rl == rr) {
                int combined = Math.Max(newAtRl, newAtRr);
                int cur = Qry1(0, 0, M-1, rl, rl);
                if (combined > cur) Upd(rl, combined);
            } 
            else {
                if (ll <= rl) { 
                    int cur = Qry1(0, 0, M-1, rl, rl); 
                    if (newAtRl > cur) Upd(rl, newAtRl); 
                }
                if (lr <= rr) { 
                    int cur = Qry1(0, 0, M-1, rr, rr); 
                    if (newAtRr > cur) Upd(rr, newAtRr); 
                }
            }
        }

        int ans = Qry1(0, 0, M-1, 0, M-1);
        return ans < 0 ? 0 : ans;
    }

    private int Best(int l, int r) {
        int prior = l == 0 ? 0 : Math.Max(0, Qry1(0, 0, M-1, 0, l-1));
        int c1 = prior + (r - l + 1);
        int c2 = l < r ? Qry2(0, 0, M-1, l, r-1) + r : NEG;
        return c2 > NEG ? Math.Max(c1, c2) : c1;
    }

    private void Upd(int idx, int v) { 
        U1(0, 0, M-1, idx, v); 
        U2(0, 0, M-1, idx, v - idx); 
    }
    
    private void U1(int nd, int s, int e, int i, int v) {
        if (s==e){
            s1[nd]=Math.Max(s1[nd],v);
            return;
        } 
        int m=(s+e)/2;
        if(i<=m)U1(2*nd+1,s,m,i,v);
        else U1(2*nd+2,m+1,e,i,v);
        s1[nd]=Math.Max(s1[2*nd+1],s1[2*nd+2]);
    }

    private void U2(int nd, int s, int e, int i, int v) {
        if (s==e){
            s2[nd]=Math.Max(s2[nd],v);
            return;
        } 
        int m=(s+e)/2;
        if(i<=m)U2(2*nd+1,s,m,i,v);
        else U2(2*nd+2,m+1,e,i,v);
        s2[nd]=Math.Max(s2[2*nd+1],s2[2*nd+2]);
    }

    private int Qry1(int nd, int s, int e, int l, int r) {
        if(r<s||e<l) return NEG; 
        if(l<=s&&e<=r) return s1[nd]; int m=(s+e)/2;
        return Math.Max(Qry1(2*nd+1,s,m,l,r),Qry1(2*nd+2,m+1,e,l,r));
    }

    private int Qry2(int nd, int s, int e, int l, int r) {
        if(r<s||e<l) return NEG; 
        if(l<=s&&e<=r) return s2[nd]; 
        int m=(s+e)/2;
        return Math.Max(Qry2(2*nd+1,s,m,l,r),Qry2(2*nd+2,m+1,e,l,r));
    }

    private int LB(int[] a, int v){
        int lo=0,hi=a.Length;
        while(lo<hi){
            int m=(lo+hi)/2;
            if(a[m]<v)lo=m+1;
            else hi=m;
        }
        return lo;
    }

    private int UB(int[] a, int v){
        int lo=0,hi=a.Length;
        while(lo<hi){
            int m=(lo+hi)/2;
            if(a[m]<=v)lo=m+1;
            else hi=m;
        }
        return lo;
    }
}