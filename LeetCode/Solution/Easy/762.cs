namespace Easy;

public class Solution {
    public int CountPrimeSetBits(int left, int right) {
        int count = 0;
        for(int num = left; num <= right; num++){
            int setBits = CountSetBits(num);
            if(IsPrime(setBits))
               count++;
        }
        return count;
    }

    private static bool IsPrime(int n){
        if(n < 2) return false;
        if(n == 2) return true;
        if(n % 2 == 0) return false;

        for(int i = 3; i * i <= n; i += 2){
            if(n % i == 0) return false;
        }
        return true;
    }

    private static int CountSetBits(int n){
        int count = 0;
        while(n > 0){
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
}