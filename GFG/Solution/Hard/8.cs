class Solution
{
    public int getCount(int n, int d)
    {
        int low = 1, high = n, firstValid = -1;
        
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if (mid - DigitSum(mid) >= d)
            {
                firstValid = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return firstValid == -1 ? 0 : n - firstValid + 1;
    }
    
    private static int DigitSum(int num)
    {
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}