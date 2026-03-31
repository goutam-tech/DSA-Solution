public class Solution {
    public bool HasAlternatingBits(int n) {
        int xor = n ^ (n >> 1);
        return (xor & (xor + 1)) == 0;
    }
}