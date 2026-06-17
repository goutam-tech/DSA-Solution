class Solution {
  public:
    bool kSubstr(string &s, int k) {
        // code here
        int n = s.length();
        
        if(n % k != 0) return false;
        
        map<string,int> m;
        
        for(int i = 0; i < n; i += k){
            
            int c = 0;
            
            string ss = "";
            int y = i;
            
            while(c != k){
                
                ss = ss + s[y];
                y++;
                c++;
            }
            
            m[ss]++;
        }
        
        int co = 0;
        int mm=0;
        if(m.size() == 1){
            return true;
        } 
        
        else{
            
            for(auto it : m){
                
                if(it.second == 1){
                    co++;
                }
                else if(it.second>=2){
                    mm++;
                }
            }
            
            if(co == 1 && mm>=1){
                return true;
            }
              if(co==2 && mm==0 ) return true;
            else{
                return false;
            }
        }
    }
};