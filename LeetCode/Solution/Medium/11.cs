namespace Hard;

public class Solution {
    public int MaxArea(int[] height) {
       int left = 0;
       int right = height.Length -1;
       int maxWater=0;

       while(left<right)
       {
         int width = right-left;
         int h = Math.Min(height[left],height[right]);
         int currentWater = h*width;

         if(currentWater>maxWater)
         {
            maxWater = currentWater;
         }

         if(height[left]<height[right])
         {
            left++;
         }
         else
         {
            right--;
         }
       }
       return maxWater;
    }
}