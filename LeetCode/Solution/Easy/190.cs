namespace Easy;

public class Solution {
    public int ReverseBits(int n) {
        int result = 0;
        int bitToProcess = 32;

        while(bitToProcess --> 0){
            result = (result << 1) | (n & 1);
            n >>= 1;
        }

        return result;
    }
}