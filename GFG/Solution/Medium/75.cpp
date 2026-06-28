class Solution {
  public:
    int maxSubstring(string &s) {
        // code here
        int maxDiff = INT_MIN, curr = 0;
        bool hasZero = false;
        
        for(char c : s){
            curr += (c == '0') ? 1 : -1;
            if(curr > maxDiff) maxDiff = curr;
            if(curr < 0) curr = 0;
            if(c == '0') hasZero = true;
        }
        return hasZero ? maxDiff : -1;
    }
};