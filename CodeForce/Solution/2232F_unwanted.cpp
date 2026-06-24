// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// ll extgcd(ll a, ll b, ll &x, ll &y){
//     if(b == 0){
//         x = 1;
//         y = 0;
//         return a;
//     }
//     ll x1, y1;
//     ll g = extgcd(b, a % b, x1, y1);
//     y = x1 - (a / b) * y1;
//     return g;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;
//     while(t--){
//         ll n, a, b, k;
//         cin >> n >> a >> b >> k;

//         bool lastOk = (k % a == 0);

//         if(n == 1){
//             cout << (lastOk ? 1 : 0) << "\n";
//             continue;
//         }

//         bool midOk = false;
//         ll g = __gcd(a, b);
//         if(k % g == 0){
//             ll A = a / g;
//             ll B = b / g;
//             ll K = k / g;

//             ll inv_x, dummy;
//             extgcd(B, A, inv_x, dummy);
//             inv_x = ((inv_x % A) + A) % A;

//             ll y0 = (K % A * inv_x) % A;

//             if(b * y0 <= k){
//                 midOk = true;
//             }
//         }

//         if(midOk){
//             cout << (n - 1) + (lastOk ? 1 : 0) << "\n";
//         }
//         else{
//             cout << (lastOk ? 1 : 0) << "\n";
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll modinv(ll a, ll m) {
    ll g=m, x=0, y=1;
    ll ta=a;
    while(ta){ll q=g/ta;g-=q*ta;swap(g,ta);x-=q*y;swap(x,y);}
    return (x%m+m)%m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll n, a, b, k;
        cin >> n >> a >> b >> k;

        bool lastOk = (k % a == 0);
        if (n == 1) { cout << (lastOk ? 1 : 0) << "\n"; continue; }

        ll ans = lastOk ? 1 : 0;
        ll g = __gcd(a, b);
        ll ag = a / g;
        ll bg = b / g;
        ll inv_bg = (ag == 1) ? 0LL : modinv(bg % ag, ag);

        ll rem = k;
        ll cnt = 0;
        ll limit = ag + 1;
        map<ll,ll> seen;

        while (cnt < n - 1) {
            if (rem % g != 0) break;
            ll rg = (rem / g) % ag;
            ll t2 = (rg * inv_bg) % ag;
            if (rem - b * t2 < 0) break;
            ll t1 = (rem - b * t2) / a;
            ll new_rem = k - b * (t1 + t2);
            if (new_rem < 0) break;
            if (seen.count(rem)) {
                ll cycle = cnt - seen[rem];
                ll remaining = (n - 1 - cnt);
                cnt += (remaining / cycle) * cycle + min(remaining % cycle, cycle);
                cnt = n - 1;
                break;
            }
            seen[rem] = cnt;
            cnt++;
            rem = new_rem;
        }

        ans = max(ans, cnt + (lastOk ? 1 : 0));
        cout << ans << "\n";
    }
    return 0;
}