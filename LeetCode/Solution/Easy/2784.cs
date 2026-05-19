public class Solution {
    public bool IsGood(int[] nums) {
        int n = nums.Length - 1;
        int[] count = new int[n + 1];

        foreach(int num in nums){
            if(num < 1 || num > n) return false;
            count[num]++;
        }

        for(int i = 1; i < n; i++){
            if(count[i] != 1) return false;
        }

        return count[n] == 2;
    }
}