#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128 int128;

std::ostream& operator<<(std::ostream& os, int128 t) {
    if (t == 0) return os << "0";
    if (t < 0) {
        os << "-";
        t = -t;
    }
    int a[50], i = 0;
    while (t > 0) {
        a[i++] = (int)(t % 10);
        t /= 10;
    }
    for (int j = i - 1; j >= 0; j--) os << (char)(a[j] + '0');
    return os;
}

void summmon() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (auto &z : a) cin >> z;

    int128 ans = 0;
    vector<int> st;
    st.reserve(n);

    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[i] % a[st.back()] > 0) {
            ll r = a[i] % a[st.back()];
            ll d = min(r, a[st.back()] - r);
            ans += (int128)(n - i) * d;
            st.pop_back();
        }
        st.push_back(i);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) summmon();

    return 0;
}