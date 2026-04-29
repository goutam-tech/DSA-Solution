public class Solution {
    public long[] Distance(int[] nums) {
        int n = nums.Length;
        long[] arr = new long[n];
        var groups = new Dictionary<int, List<int>>();
        
        for (int i = 0; i < n; i++) {
            if (!groups.ContainsKey(nums[i]))
                groups[nums[i]] = new List<int>();
            groups[nums[i]].Add(i);
        }
        
        foreach (var group in groups.Values) {
            int m = group.Count;
            if (m == 1) continue;
            
            long prefixSum = 0;
            for (int i = 0; i < m; i++) {
                long idx = group[i];
                arr[group[i]] += idx * i - prefixSum;
                prefixSum += idx;
            }
            
            long suffixSum = 0;
            for (int i = m - 1; i >= 0; i--) {
                long idx = group[i];
                arr[group[i]] += suffixSum - idx * (m - 1 - i);
                suffixSum += idx;
            }
        }
        
        return arr;
    }
}