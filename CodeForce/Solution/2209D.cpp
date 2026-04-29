#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int C = 3;
void solve(){
    int c[C];
    string rgb = "RGB";
    cin >> c[0] >> c[1] >> c[2];
    string ans;
    while(true){
        int p[] = {0,1,2};
        sort(p, p + C, [&](int i, int j){
            if(c[i] != c[j])
              return c[i] > c[j];
            if(ans.size() > 1 && ans[ans.size() - 2] == rgb[i])  // Fix 1
              return true;
            if(ans.size() > 1 && ans[ans.size() - 2] == rgb[j])  // Fix 1
              return false;
            return i < j;
        });
        bool done = false;
        for (int i : p)
          if (static_cast<bool>(c[i]) &&
              (ans.empty() || ans.back() != rgb[i]) &&
              (ans.size() < 3 || ans[ans.size() - 3] != rgb[i])) {
              ans += rgb[i];
              --c[i];
              done = true;
          }
       if(!done)
          break;
    }
    cout << ans << '\n';
}
int main(){
    int t;
    cin >> t;
    while( static_cast<bool>(t--))
       solve();
}