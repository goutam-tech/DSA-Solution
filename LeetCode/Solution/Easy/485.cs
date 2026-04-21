namespace Easy;

public class Solution {
    public int FindMaxConsecutiveOnes(int[] nums) {
        int maxCount = 0;
        int currentCount = 0;

        foreach(int num in nums){
            if(num ==1){
                currentCount++;
                maxCount = Math.Max(maxCount, currentCount);
            }
            else{
                currentCount =0;
            }
        }
        return maxCount;
    }
}