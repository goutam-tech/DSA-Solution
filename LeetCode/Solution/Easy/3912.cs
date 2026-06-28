public class Solution {
    public IList<int> FindValidElements(int[] nums) {
        int n = nums.Length;
        var valid = new bool[n];
        
        valid[0] = valid[n - 1] = true;

        int maxLeft = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > maxLeft) {
                valid[i] = true;
            }
            maxLeft = Math.Max(maxLeft, nums[i]);
        }
        
        int maxRight = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > maxRight) {
                valid[i] = true;
            }
            maxRight = Math.Max(maxRight, nums[i]);
        }
        

        var result = new List<int>();
        for (int i = 0; i < n; i++) {
            if (valid[i]) {
                result.Add(nums[i]);
            }
        }
        
        return result;
    }
}