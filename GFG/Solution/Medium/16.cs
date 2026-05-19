class Solution {
    public int derangeCount(int n) {
        // code here
        if(n == 1) return 0;
        if(n == 2) return 1;
        
        int a = 0, b = 1;
        for(int i = 3; i <=n; i++){
            int c = (i - 1) * (a + b);
            a = b;
            b = c;
        }
        
        return b;
    }
};