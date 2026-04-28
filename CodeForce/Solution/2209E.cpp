#include <bits/stdc++.h>
using namespace std;

using ll = long long;

static vector<int> build_z(const string &t) {
    int n = (int)t.size();
    vector<int> z(n, 0);
    if (n == 0)
        return z;
    z[0] = n;

    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i < r)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && t[z[i]] == t[i + z[i]])
            ++z[i];
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (static_cast<bool>(T--)) {
        int n, q;
        cin >> n >> q;

        string s;
        cin >> s;

        vector<pair<int, int>> queries(q);
        unordered_map<int, vector<pair<int, int>>> groups;
        groups.reserve(q * 2);

        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            queries[i] = {l, r};
            groups[l].push_back({i, r});
        }

        vector<ll> ans(q);

        for (auto &entry : groups) {
            int l = entry.first;
            auto &vec = entry.second;

            int maxR = 0;
            for (auto &it : vec)
                maxR = max(maxR, it.second);

            int m = maxR - l + 1;
            //string t = s.substr(l - 1, m);
            string t = s.substr(static_cast<string::size_type>(l - 1), static_cast<string::size_type>(m));

            vector<int> z = build_z(t);

            vector<int> F(m + 1, 0);
            vector<ll> pref(m + 1, 0);

            vector<pair<int, int>> st;
            st.reserve(m);

            for (int x = 1; x <= m; ++x) {
                int p = x - 1;
                if (p >= 1) {
                    st.push_back({p, p + z[p]});
                }

                while (!st.empty() && st.back().second < x) {
                    st.pop_back();
                }

                int pre = st.empty() ? 0 : st.back().first;
                F[x] = F[pre] + 1;
                pref[x] = pref[x - 1] + F[x];
            }

            for (auto &[idx, r] : vec) {
                int len = r - l + 1;
                ans[idx] = pref[len];
            }
        }

        for (int i = 0; i < q; ++i) {
            cout << ans[i] << '\n';
        }
    }

    return 0;
}