class Solution {
  public:
    string lexicographicallySmallest(string &s, int k) {
        // code here
        int n = s.size();
        
        long long len = n;
        bool isPow2 = len > 0 && (len & (len - 1)) == 0;
        long long ck = isPow2 ? k / 2 : (long long)k * 2;
        
        if(ck > n || (long long)n - ck == 0) return "-1";
        
        int remove = (int)ck;
        int remain = n - remove;
        
        string res;
        res.reserve(remain);
        
        int top = 0;
        for(int i = 0; i < n; i++){
            while(top > 0 && remove > 0 && res[top - 1] > s[i]){
                res.pop_back();
                top--;
                remove--;
            }
            res.push_back(s[i]);
            top++;
        }
        
        res.resize(remain);
        return res;
    }
};