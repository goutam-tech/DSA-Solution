class Solution {
  public:
    int getLastDigit(string& a, string& b) {
        // code here
        if(b.size() == 1 && b[0] == '0') return 1;
        if(a.size() == 1 && a[0] == '0') return 0;
        
        int mod = 0;
        for(char c : b){
            mod = (mod * 10 + (c - '0')) % 4;
        }
        int e = (mod == 0) ? 4 : mod;
        int d = a.back() - '0', res = 1;
        for(int i = 0; i < e; i++){
            res = (res * d) % 10;
        }
        
        return res;
    }
};