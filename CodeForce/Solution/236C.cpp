#include <bits/stdc++.h>
using namespace std;

long long lcm(long long a, long long b){
    return a / __gcd(a, b) * b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    if(n == 1){
        cout << 1;
        return 0;
    }
    if(n == 2){
        cout << 2;
        return 0;
    }

    long long ans = 0;
    for(long long i = n; i >= max(1LL, n - 3); i--){
        for(long long j = i; j >= max(1LL, n - 3); j--){
            for(long long k = j; k >= max(1LL, n - 3); k--){
                ans = max(ans, lcm(i, (lcm(j, k))));
            }
        }
    }
    cout << ans << "\n";
}