using System;
using System.Numerics;

public class Solution {
    public int SmallestBalancedIndex(int[] nums) {
        int n = nums.Length;
        if (n == 0) return -1;

        BigInteger totalSum = 0;
        foreach (int num in nums) {
            totalSum += Math.Abs(num);
        }

        BigInteger[] suffixProducts = new BigInteger[n + 1];
        suffixProducts[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            suffixProducts[i] = suffixProducts[i + 1] * nums[i];

            if (suffixProducts[i + 1] != 0 && nums[i] != 0) {
                if (BigInteger.Abs(suffixProducts[i]) > totalSum + 2) {
                    suffixProducts[i] = (suffixProducts[i].Sign > 0) ? totalSum + 2 : -(totalSum + 2);
                }
            }
        }

        BigInteger leftSum = 0;
        for (int i = 0; i < n; i++) {
            if (leftSum == suffixProducts[i + 1]) {
                return i;
            }
            leftSum += nums[i];
        }

        return -1;
    }
}