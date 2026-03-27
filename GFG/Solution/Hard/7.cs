class Solution 
{
    public long minTime(int[] arr, int k) 
    {
        int n = arr.Length;
        
        if (k >= n) 
        {
            return arr.Max();
        }
        
        long left = arr.Max();  
        long right = arr.Sum(); 
        long result = right;
        
        while (left <= right) 
        {
            long mid = left + (right - left) / 2;
            
            if (CanPaintInTime(arr, k, mid)) 
            {
                result = mid;
                right = mid - 1; 
            } 
            else 
            {
                left = mid + 1; 
            }
        }
        
        return result;
    }
    
    private bool CanPaintInTime(int[] arr, int k, long maxTime) 
    {
        int paintersUsed = 1;
        long currentTime = 0;  
        
        for (int i = 0; i < arr.Length; i++) 
        {
            if (currentTime + arr[i] > maxTime) 
            {
                paintersUsed++;
                currentTime = arr[i];
                
                if (paintersUsed > k) 
                {
                    return false;
                }
            } 
            else 
            {
                currentTime += arr[i];
            }
        }
        
        return true;
    }
}