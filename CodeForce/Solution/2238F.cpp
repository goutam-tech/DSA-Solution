# include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e6 + 1;
const ll mod = 1e9 + 7;

struct md{
    ll x;
    md(ll p = 0){
        x = ((p % mod) + mod) % mod;
    }
    md operator+ (md other) const {
        ll p = x + other.x;
        if(p >= mod) p -= mod;
        return md(p);
    }
    md operator- (md other) const {
        ll p = x - other.x;
        if(p < 0) p += mod;
        return md(p);
    }
    md operator* (md other) const {
        return md(1ll * x * other.x % mod);
    }
    md operator^ (ll e) const {
        md base = *this, res(1);
        while(e > 0){
            if(e & 1) res = res * base;
            base = base * base;
            e >>= 1;
        }
        return res;
    }
    md operator/ (md p) const {
        return *this * (p ^ (mod - 2));
    }
};


vector<md> fact, rfact;

void prec() {
    fact.resize(maxn);
    rfact.resize(maxn);
    fact[0] = md(1);
    for (int i = 1; i < maxn; ++i) fact[i] = fact[i - 1] * md(i);
    rfact[maxn - 1] = md(1) / fact[maxn - 1];
    for (int i = maxn - 2; i >= 0; --i) rfact[i] = rfact[i + 1] * md(i + 1);
}

md C(int n, int k) {
    if (n < 0 || k < 0 || k > n) return md(1);
    return fact[n] * rfact[k] * rfact[n - k];
}

md catalan(int n) {
    if (n == 0) return md(1);
    return C(2 * n, n) - C(2 * n, n - 1);
}

void infinitWork(){
    ll n, k;
    cin >> n >> k;
    k++;
    vector<ll> bits(61, 0);
    for(int i = 0; i < 61; i++){
        bits[i] = (k >> i) & 1;
    }
    for(ll x = 60; x >= n; x--){
        bits[x - 1] += 2 * bits[x];
        bits[x] = 0;
    }
    int sm = 0;
    for(int i = 0; i < 61; ++i){
        sm += bits[i];
    }

    md an = catalan(sm - 1) * fact[sm];
    for(int i = 0; i < 61; ++i){
        if(bits[i] >= 2) an = an * rfact[bits[i]];
    }
    cout << an.x << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    prec();
    int t;
    cin >> t;
    while(t--){
        infinitWork();
    }
    return 0;
}