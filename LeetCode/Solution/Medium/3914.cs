using System;

public class Solution {
    public long MinOperations(int[] nums) {
        long ops = 0;
        for (int i = 1; i < nums.Length; i++) {
            if (nums[i] < nums[i - 1]) {
                ops += (long)(nums[i - 1] - nums[i]);
            }
        }
        return ops;
    }
}