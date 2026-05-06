class Solution {
    public int findPosition(int n) {
        // code here
        if(n <= 0 || (n & (n - 1)) != 0){
            return -1;
        }
        
        return (int)Math.Log2(n) + 1;
    }
}