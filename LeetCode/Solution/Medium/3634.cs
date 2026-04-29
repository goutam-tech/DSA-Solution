public class Solution {
    public int MinRemoval(int[] nums, int k) {
        Array.Sort(nums);

        int n = nums.Length;
        int left = 0;
        int maxWindow = 1;

        for(int right = 0; right < n; right++){
            while((long)nums[right] > (long)nums[left] * k){
                left++;
            }
            maxWindow = Math.Max(maxWindow, right-left+1);
        }

        return (n-maxWindow);
    }
}