#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> par(n + 1, 0);
    vector<vector<int>> children(n + 1);

    for (int i = 2; i <= n; i++) {
        cin >> par[i];
        children[par[i]].push_back(i);
    }

    vector<int> depth(n + 1, 0);
    for (int v = n; v >= 1; v--)
        for (int c : children[v])
            depth[v] = max(depth[v], depth[c] + 1);

    vector<int> msib(n + 1, -1);
    for (int p = 1; p <= n; p++) {
        if (children[p].empty()) continue;
        int max1 = -1, max2 = -1, who1 = -1;
        for (int c : children[p]) {
            if (depth[c] > max1) { max2 = max1; max1 = depth[c]; who1 = c; }
            else if (depth[c] > max2) { max2 = depth[c]; }
        }
        for (int c : children[p]) {
            msib[c] = (c == who1) ? max2 : max1;
        }
    }

    long long ans = depth[1] + 1;
    for (int v = 2; v <= n; v++) {
        if (msib[v] >= 0)
            ans += min(depth[v], msib[v]) + 1;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}