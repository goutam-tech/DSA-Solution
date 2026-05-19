class Solution {
    public int[] smallestDiff(int[] a, int[] b, int[] c) {
        Array.Sort(a);
        Array.Sort(b);
        Array.Sort(c);
        
        int i = 0,j = 0,k = 0;
        int minDiff = int.MaxValue;
        int minSum = int.MaxValue;
        int[] result = new int[3];
        
        while(i<a.Length && j<b.Length && k<c.Length){
            int x = a[i], y = b[j],z = c[k];
            
            int currentMin = Math.Min(x, Math.Min(y,z));
            int currentMax = Math.Max(x, Math.Max(y,z));
            int diff = currentMax - currentMin;
            int sum = x+y+z;
            
            if(diff < minDiff || (diff == minDiff && sum < minSum)){
                minDiff = diff;
                minSum = sum;
                result[0] = x;
                result[1] = y;
                result[2] = z;
            }
            
            if(currentMin == x) i++;
            else if(currentMin == y) j++;
            else k++;
        }
        
        Array.Sort(result);
        Array.Reverse(result);
        
        return result;
    }
}