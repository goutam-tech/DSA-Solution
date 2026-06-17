#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int c[5] = {};
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        c[x]++;
    }

    int taxis = 0;

    taxis += c[4];

    int paried = min(c[3], c[1]);
    taxis += paried;
    c[1] -= paried;
    c[3] -= paried;

    taxis += c[3];

    taxis += c[2] / 2;
    if(c[2] % 2 == 1){
        taxis++;
        c[1] = max(0, c[1] - 2);
    }

    taxis += (c[1] + 3) / 4;

    cout << taxis << "\n";
}