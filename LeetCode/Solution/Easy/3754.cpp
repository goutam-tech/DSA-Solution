class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, sum = 0;
        if(n == 0) return 0;
        string s = to_string(n);

        for(char c : s){
            int d = c - '0';
            if(d != 0){
                x = x * 10 + d;
                sum += d;
            }
        }

        return x * sum;
    }
};