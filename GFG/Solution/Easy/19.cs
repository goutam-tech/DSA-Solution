public class Solution {
    public List<int> findMean(int[] arr, int[][] queries) {
        int n = arr.Length;
        long[] prefix = new long[n + 1];
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + arr[i];
        
        List<int> result = new List<int>(queries.Length);
        foreach (var q in queries)
            result.Add((int)((prefix[q[1] + 1] - prefix[q[0]]) / (q[1] - q[0] + 1)));
        
        return result;
    }
}