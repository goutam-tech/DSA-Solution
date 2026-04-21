namespace Easy;

public class Solution {
    public int CountMonobit(int n) {
        int count = 1;
        long monobit = 1;

        while(monobit <= n){
            count++;
            monobit = (monobit << 1) | 1;
        }

        return count;
    }
}