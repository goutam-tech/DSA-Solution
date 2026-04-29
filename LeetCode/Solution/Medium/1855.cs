public class Solution {
    public int MaxDistance(int[] nums1, int[] nums2) {
        int i = 0, j = 0, result = 0;
        while(i < nums1.Length && j < nums2.Length){
            if(nums1[i] <= nums2[j]){
                result = Math.Max(result, j - i);
                j++;
            }
            else{
                i++;
                if(j < i) j = i;
            }
        }

        return result;
    }
}