# include <bits/stdc++.h>
using namespace std;

void alternativeWay(){
    int n;
    cin >> n;

    vector<long long> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    long long pa = 0, pb = 0;
    bool ok = true;
    for(int i = 0; i < n; i++){
        pa += a[i];
        pb += b[i];
        if(pb < pa) ok = false;
    }

    cout << (ok ? "YES" : "NO") <<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
        alternativeWay();

    return 0;
}