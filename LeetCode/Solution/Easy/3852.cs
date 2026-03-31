using System;
using System.Collections.Generic;

public class Solution {
    public int[] MinDistinctFreqPair(int[] nums) {
        var freq = new Dictionary<int,int>();
        foreach (var n in nums) {
            if (freq.ContainsKey(n)) freq[n]++;
            else freq[n] = 1;
        }

        var keys = new List<int>(freq.Keys);
        keys.Sort();

        for (int i = 0; i < keys.Count; i++) {
            for (int j = i + 1; j < keys.Count; j++) {
                if (freq[keys[i]] != freq[keys[j]]) {
                    return new int[] { keys[i], keys[j] };
                }
            }
        }

        return new int[] { -1, -1 };
    }
}