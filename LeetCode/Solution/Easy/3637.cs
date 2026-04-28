namespace Easy;

public class Solution {
    public bool IsTrionic(int[] nums) {
        int n = nums.Length;

        if(n<4) return false;

        int i=0;

        while(i+1 < n && nums[i] < nums[i+1])
           i++;
        if(i==0) return false;

        int p=i;
        while(i+1 < n && nums[i] > nums[i+1])
           i++;
        if(i==p) return false;

        int q=i;
        while(i+1 < n && nums[i] < nums[i+1])
           i++;
        
        return i==n -1 && q < n-1;
    }
}