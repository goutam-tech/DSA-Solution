public class Solution {
    public int RotatedDigits(int n) {
        int count = 0;
        for(int i = 0; i <= n; i++){
            if(IsGood(i)) count++;
        }
        return count;
    }

    private bool IsGood(int x){
        bool different = false;
        int temp = x;
        while(temp > 0){
            int d = temp % 10;
            if(d == 3 || d == 4 || d == 7) return false;
            if(d == 2 || d == 5 || d == 6 || d == 9) different = true;
            temp /= 10; 
        }

        return different;
    }
}