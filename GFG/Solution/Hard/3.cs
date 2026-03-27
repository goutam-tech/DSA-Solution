public class Solution {
    public int maxCircularSum(int[] arr) {
        int n = arr.Length;

        int totalSum = arr[0];

        int maxKadane = arr[0];
        int currentMax = arr[0];

        int minKadane = arr[0];
        int currentMin = arr[0];

        for (int i = 1; i < n; i++)
        {
            totalSum += arr[i];

            currentMax = Math.Max(arr[i], currentMax + arr[i]);
            maxKadane = Math.Max(maxKadane, currentMax);

            currentMin = Math.Min(arr[i], currentMin + arr[i]);
            minKadane = Math.Min(minKadane, currentMin);
        }
        
        if (maxKadane < 0)
            return maxKadane;

        return Math.Max(maxKadane, totalSum - minKadane);
    }
}