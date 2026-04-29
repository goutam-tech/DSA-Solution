public class Solution {
    public int LongestBalanced(int[] nums) {
        int n = nums.Length;
        int maxLen = 0;

        for(int i = 0; i < n; i++){
            HashSet<int> evenSet = new HashSet<int>();
            HashSet<int> oddSet = new HashSet<int>();

            for(int j = i; j < n; j++){
                if(nums[j] % 2 == 0)
                   evenSet.Add(nums[j]);

                else
                   oddSet.Add(nums[j]);

                if(evenSet.Count == oddSet.Count)
                   maxLen = Math.Max(maxLen, j-i+1);
            }
        }

        return maxLen;
    }
}