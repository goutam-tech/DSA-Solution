public class Solution {
    public int MinMoves(int[] nums, int limit) {
        int n = nums.Length;
        int[] delta = new int[2 * limit + 2];

        for(int i = 0; i < n / 2; i++){
            int a = nums[i], b = nums[n - 1 - i];
            int lo = 1 + Math.Min(a, b);
            int hi = limit + Math.Max(a, b);
            int exact = a + b;

            delta[lo] -= 1;
            delta[hi + 1] += 1;

            delta[exact] -= 1;
            delta[exact + 1] += 1;
        }

        int minMoves = n;
        int current = n;
        for(int t = 2; t <= 2 * limit; t++){
            current += delta[t];
            minMoves = Math.Min(minMoves, current);
        }

        return minMoves;
    }
}