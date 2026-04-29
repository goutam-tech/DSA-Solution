public class Solution {
    public int ThreeSumClosest(int[] nums, int target) {
        Array.Sort(nums);
        int closest = nums[0] + nums[1] + nums[2];

        for(int i=0;i<nums.Length - 2; i++){
            int left = i+1;
            int right = nums.Length -1;
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];

                if(Math.Abs(sum - target) < Math.Abs(closest - target)){
                    closest = sum;
                }
                else if(sum<target){
                    left++;
                }
                else if(sum>target){
                    right--;
                }
                else{
                    return sum;
                }
            }
        }
        return closest;
    }
}