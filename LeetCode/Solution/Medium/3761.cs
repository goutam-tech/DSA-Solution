public class Solution {
    public int MinMirrorPairDistance(int[] nums) {
        var seen = new Dictionary<int, int>();
        int minDist = int.MaxValue;

        for (int j = 0; j < nums.Length; j++) {
            int rev = Reverse(nums[j]);

            if (seen.TryGetValue(nums[j], out int i)) {
                minDist = Math.Min(minDist, j - i);
                if (minDist == 1) return 1;
            }

            seen[rev] = j;
        }

        return minDist == int.MaxValue ? -1 : minDist;
    }

    private int Reverse(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }
}