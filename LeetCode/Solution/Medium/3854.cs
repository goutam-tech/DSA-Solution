public class Solution {
    public int[] MakeParityAlternating(int[] nums) {
        if (nums.Length == 1) return new int[] { 0, 0 };

        int zero = 0, one = 0;
        for (int i = 0; i < nums.Length; i++) {
            if ((nums[i] & 1) != (i & 1)) zero++;
            if ((nums[i] & 1) != ((i + 1) & 1)) one++;
        }

        int[] ans = new int[2];
        ans[0] = Math.Min(one, zero);

        if (one == zero) ans[1] = Math.Min(Fun(nums, 0), Fun(nums, 1));
        else if (one > zero) ans[1] = Fun(nums, 0);
        else ans[1] = Fun(nums, 1);

        return ans;
    }

    public int Fun(int[] nums, int parity) {
        int max = int.MinValue;
        int min = int.MaxValue;

        for (int i = 0; i < nums.Length; i++) {
            if ((nums[i] & 1) == ((i + parity) & 1)) {
                max = Math.Max(max, nums[i]);
                min = Math.Min(min, nums[i]);
            } else {
                max = Math.Max(max, nums[i] - 1);
                min = Math.Min(min, nums[i] + 1);
            }
        }

        return Math.Max(max - min, 1);
    }
}