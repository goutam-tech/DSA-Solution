public class Solution {
    public int[] MaxValue(int[] nums) {
        int[] ans = new int[nums.Length];
        int greatest = 0;
        
        for (int i = 0; i < nums.Length; i++) {
            if (nums[i] > greatest) {
                greatest = nums[i];
            }
            ans[i] = greatest;
        }

        List<int[]> smallestAt = new List<int[]>();
        int smallest = int.MaxValue;
        for (int i = nums.Length - 1; i >= 0; i--) {
            if (nums[i] < smallest) {
                smallest = nums[i];
                smallestAt.Add(new int[2] {smallest, i});
            }
        }

        for (int i = nums.Length - 1; i >= 0; i--) {
            int left = 0;
            int right = smallestAt.Count;
            while (right > left) {
                int middle = (right - left) / 2 + left; 
                if (smallestAt[middle][0] < ans[i]) {
                    right = middle;
                }
                else {
                    left = middle + 1;
                }
            }
            if (left < smallestAt.Count && ans[smallestAt[left][1]] > ans[i]) {   
                ans[i] = ans[smallestAt[left][1]];
            }
        }

        return ans;
    }
}