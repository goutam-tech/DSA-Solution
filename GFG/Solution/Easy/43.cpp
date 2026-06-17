class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == ')'){
                count++;
            }
        }
        return count;
    }
};