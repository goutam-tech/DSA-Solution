#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    double E_score = 0, E_len = 0;
    for(int i = 0; i < n; i++){
        double p;
        cin >> p;
        E_score += p * (2 * E_len + 1);
        E_len = p * (E_len + 1);
    }
    cout << fixed << setprecision(15) << E_score << "\n";
}