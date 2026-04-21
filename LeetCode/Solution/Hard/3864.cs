using System;

namespace Hard;

public class Solution {
    public long MinCost(string s, int encCost, int flatCost) {
        int n = s.Length;
        int[] pref = new int[n + 1];
        
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (s[i] - '0');
        }
        
        return GetMinCost(0, n, pref, encCost, flatCost);
    }

    private long GetMinCost(int start, int len, int[] pref, long encCost, long flatCost) {
        long x = pref[start + len] - pref[start];
        long cost = x == 0 ? flatCost : len * x * encCost;
        
        if (len % 2 == 0) {
            long splitCost = GetMinCost(start, len / 2, pref, encCost, flatCost) + 
                             GetMinCost(start + len / 2, len / 2, pref, encCost, flatCost);
            
            if (splitCost < cost) {
                cost = splitCost;
            }
        }
        
        return cost;
    }
}