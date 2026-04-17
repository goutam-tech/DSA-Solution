public class Solution {
    public double FindMedianSortedArrays(int[] nums1, int[] nums2) 
    {
       int m = nums1.Length;
       int n = nums2.Length;
       int[] num3 = new int[m+n];

       Array.Copy(nums1,0,num3,0,m);
       Array.Copy(nums2,0,num3,m,n);

       Array.Sort(num3);
         
       int mid = num3.Length/2;
       double median;
       if(num3.Length % 2 ==0)
       {
            median = (num3[mid-1]+num3[mid]) / 2.0;
       }
       else{
          median = num3[mid];
       }
       return median;  
    }
}