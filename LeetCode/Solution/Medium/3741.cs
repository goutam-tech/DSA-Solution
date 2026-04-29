using System;
using System.Collections.Generic;

public class Solution {
    public int MinimumDistance(int[] nums) {
        var map = new Dictionary<int, List<int>>();
        for (int i = 0; i < nums.Length; i++) {
            if (!map.ContainsKey(nums[i])) map[nums[i]] = new List<int>();
            map[nums[i]].Add(i);
        }

        int res = int.MaxValue;
        foreach (var kv in map) {
            var list = kv.Value;
            if (list.Count < 3) continue;
            for (int i = 0; i + 2 < list.Count; i++) {
                int dist = 2 * (list[i + 2] - list[i]);
                if (dist < res) res = dist;
            }
        }

        return res == int.MaxValue ? -1 : res;
    }
}