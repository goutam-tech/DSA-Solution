#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), g(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> g[i];

    string res(n, '?');
    int sa = 0, sg = 0;

    for(int i = 0; i < n; i++){
        if(sa + a[i] <= sg + 500){
            res[i] = 'A';
            sa += a[i];
        } else {
            res[i] = 'G';
            sg += g[i];
        }
    }

    cout << res << "\n";
}