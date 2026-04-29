namespace Easy;

public class Solution {
    public int MinimumDifference(int[] nums, int k) {
        Array.Sort(nums);
        int n = nums.Length;
        int minDiff = int.MaxValue;

        for(int i=0; i <= n-k; i++){
            int diff = nums[i+k-1] - nums[i];
            if ( diff < minDiff){
                minDiff = diff;
            }
        }
        return minDiff;
    }
}