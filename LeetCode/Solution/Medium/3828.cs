public class Solution {
    public int FinalElement(int[] nums) {
        return Math.Max(nums[0], nums[nums.Length - 1]);
    }
}