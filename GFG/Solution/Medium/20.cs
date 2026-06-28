public class Solution {
    public int[] stableMarriage(int[][] men, int[][] women) {
        int n = men.Length;
        int[] womanPartner = new int[n];
        int[] manPartner = new int[n];
        int[] nextProposal = new int[n];
        
        Array.Fill(womanPartner, -1);
        Array.Fill(manPartner, -1);
        
        int[][] womanRank = new int[n][];
        for (int i = 0; i < n; i++) {
            womanRank[i] = new int[n];
            for (int j = 0; j < n; j++)
                womanRank[i][women[i][j]] = j;
        }
        
        Queue<int> free = new Queue<int>();
        for (int i = 0; i < n; i++) free.Enqueue(i);
        
        while (free.Count > 0) {
            int m = free.Dequeue();
            int w = men[m][nextProposal[m]++];
            if (womanPartner[w] == -1) {
                womanPartner[w] = m;
                manPartner[m] = w;
            } else {
                int curr = womanPartner[w];
                if (womanRank[w][m] < womanRank[w][curr]) {
                    womanPartner[w] = m;
                    manPartner[m] = w;
                    manPartner[curr] = -1;
                    free.Enqueue(curr);
                } else {
                    free.Enqueue(m);
                }
            }
        }

        return manPartner;
    }
}