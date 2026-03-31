class Solution {
    public int maxMinHeight(int[] arr, int k, int w) {
        int n = arr.Length;
        
        bool CanAchieveMinHeight(int target)
        {
            int[] heights = new int[n];
            Array.Copy(arr, heights, n);
            int daysUsed = 0;
            int i = 0;
            
            while (i < n)
            {
                if (heights[i] < target)
                {
                    int increaseNeeded = target - heights[i];
                    daysUsed += increaseNeeded;
                    
                    for (int j = i; j < Math.Min(i + w, n); j++)
                    {
                        heights[j] += increaseNeeded;
                    }
                    
                    i++;
                }
                else
                {
                    i++;
                }
                
                if (daysUsed > k)
                {
                    return false;
                }
            }
            
            return daysUsed <= k;
        }
        
        int left = arr.Min();
        int right = arr.Min() + k;
        int result = left;
        
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            
            if (CanAchieveMinHeight(mid))
            {
                result = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        
        return result;
    }
}