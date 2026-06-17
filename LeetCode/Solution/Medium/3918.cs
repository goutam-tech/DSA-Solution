public class Solution {
    public int SumOfPrimesInRange(int n) {
        int mavroliken = n;
        
        int r = 0, temp = n;
        while (temp > 0) {
            r = r * 10 + temp % 10;
            temp /= 10;
        }
        
        int left = Math.Min(n, r);
        int right = Math.Max(n, r);
        
        int sum = 0;
        for (int i = left; i <= right; i++) {
            if (IsPrime(i)) sum += i;
        }
        
        return sum;
    }
    
    private bool IsPrime(int x) {
        if (x < 2) return false;
        if (x == 2) return true;
        if (x % 2 == 0) return false;
        
        int limit = (int)Math.Sqrt(x);
        for (int i = 3; i <= limit; i += 2) {
            if (x % i == 0) return false;
        }
        
        return true;
    }
}