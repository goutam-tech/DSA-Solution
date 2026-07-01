class Solution {
    public:
      int minInsAndDel(vector<int> &a, vector<int> &b) {
          // code here
          int n = a.size(), m = b.size();
          set<int> sb(b.begin(), b.end());
          vector<int> filtered;
          for(int x : a){
              if(sb.count(x)) filtered.push_back(x);
          }
          
          map<int, int> pos;
          for(int i = 0; i < m; i++){
              pos[b[i]] = i;
          }
          
          vector<int> lis;
          for(int x : filtered){
              int idx = pos[x];
              auto it = lower_bound(lis.begin(), lis.end(), idx);
              if(it == lis.end()){
                  lis.push_back(idx);
              }
              else *it = idx;
          }
          
          int lisLen = lis.size();
          return (n - lisLen) + (m - lisLen);
      }
  };