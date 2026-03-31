public class Solution {
    public int[] Shuffle(int[] nums, int n) {
        int[] res = new int[2*n];
        int ind = 0;

        for (int i = 0; i < n; i++) { 
            res[ind++] = nums[i];  
            res[ind++] = nums[i + n];  
        } 
        return res; 
    }
}