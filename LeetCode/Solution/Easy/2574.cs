public class Solution {
    public int[] LeftRightDifference(int[] nums) {
        int n = nums.Length;
        int[] answer = new int[n];
        int leftSum = 0, totalSum = 0;

        foreach(int x in nums) totalSum += x;

        for(int i = 0; i < n; i++){
            int rightSum = totalSum - leftSum - nums[i];
            answer[i] = Math.Abs(leftSum - rightSum);
            leftSum += nums[i];
        }
        return answer;
    }
}