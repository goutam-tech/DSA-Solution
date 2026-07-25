# include <bits/stdc++.h>
using namespace std;

void goodTimes(){
    long long x;
    cin >> x;

    long long y = 1;
    long long t = x;
    while(t > 0){
        y *= 10;
        t /= 10;
    }

    cout << y + 1 << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
        goodTimes();
    return 0;
}