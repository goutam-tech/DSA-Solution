namespace Easy;

public class Solution {
    public int GetMinDistance(int[] nums, int target, int start) {
        int minDist = int.MaxValue;
        for(int i = 0; i < nums.Length; i++){
            if(nums[i] == target){
                int dist = Math.Abs(i - start);
                if(dist < minDist) minDist = dist;
            }
        }
        return minDist;
    }
}