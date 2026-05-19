class Solution {
    public int myAtoi(string s) {
        // code here
        int i = 0;
        int n = s.Length;
        
        while(i < n && s[i] == ' '){
            i++;
        }
        
        int sign = 1;
        if(i < n && (s[i] == '+' || s[i] == '-')){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        long result = 0;
        while(i < n && char.IsDigit(s[i])){
            int digit = s[i] - '0';
            result = result * 10 + digit;
            
            if(result * sign > int.MaxValue) return int.MaxValue;
            if(result * sign < int.MinValue) return int.MinValue;
            
            i++;
        }
        
        return (int)(result * sign);
    }
}