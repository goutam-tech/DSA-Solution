using System;
using System.Linq;

public class Solution {
    public int maxProfit(int x, int y, int[] a, int[] b) {
        int n = a.Length;
        int[] idx = Enumerable.Range(0, n).ToArray();
        
        Array.Sort(idx, (i, j) => Math.Abs(b[j] - a[j]) - Math.Abs(b[i] - a[i]));
        
        long ans = 0;
        foreach (int i in idx) {
            if ((a[i] > b[i] && x > 0) || y == 0) {
                ans += a[i]; x--;
            } else {
                ans += b[i]; y--;
            }
        }
        return (int)ans;
    }
}