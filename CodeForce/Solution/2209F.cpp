#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct TopKSum {
    int K;
    multiset<ll> small, big;
    ll sumBig = 0;

    TopKSum(int K = 0) : K(K) {}

    void insertValue(ll x) {
        if (K == 0) {
            small.insert(x);
            return;
        }
        if ((int)big.size() < K) {
            big.insert(x);
            sumBig += x;
            return;
        }
        auto itMinBig = big.begin();
        if (x > *itMinBig) {
            ll y = *itMinBig;
            big.erase(itMinBig);
            sumBig -= y;
            small.insert(y);

            big.insert(x);
            sumBig += x;
        } else {
            small.insert(x);
        }
    }

    void eraseValue(ll x) {
        if (K == 0) {
            auto it = small.find(x);
            small.erase(it);
            return;
        }
        auto itBig = big.find(x);
        if (itBig != big.end()) {
            big.erase(itBig);
            sumBig -= x;
            if (!small.empty()) {
                auto it = prev(small.end());
                ll y = *it;
                small.erase(it);
                big.insert(y);
                sumBig += y;
            }
        } else {
            auto it = small.find(x);
            small.erase(it);
        }
    }

    ll query() const { return sumBig; }
};

struct Best {
    int dist;
    int leaf;
    int src;
};

static inline bool betterBest(const Best &a, const Best &b) {
    if (a.dist != b.dist)
        return a.dist > b.dist;
    return a.leaf < b.leaf;
}

static inline void relaxBest(Best cand, Best &mx1, Best &mx2) {
    if (betterBest(cand, mx1)) {
        mx2 = mx1;
        mx1 = cand;
    } else if (betterBest(cand, mx2)) {
        mx2 = cand;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<ll> a(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> a[i];

        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> deg(n + 1);
        for (int i = 1; i <= n; ++i)
            deg[i] = (int)g[i].size();

        vector<int> isLeaf(n + 1, 0);
        if (n == 1) {
            isLeaf[1] = 1;
        } else {
            for (int i = 1; i <= n; ++i) {
                if (deg[i] == 1)
                    isLeaf[i] = 1;
            }
        }

        vector<int> parent(n + 1, 0), order;
        vector<vector<int>> children(n + 1);
        order.reserve(n);

        {
            stack<int> st;
            st.push(1);
            parent[1] = -1;
            while (!st.empty()) {
                int u = st.top();
                st.pop();
                order.push_back(u);
                for (int v : g[u]) {
                    if (v == parent[u])
                        continue;
                    parent[v] = u;
                    children[u].push_back(v);
                    st.push(v);
                }
            }
        }

        vector<int> downDist(n + 1, -1), downLeaf(n + 1, (int)1e9);

        for (int idx = n - 1; idx >= 0; --idx) {
            int u = order[idx];
            Best best{-1, (int)1e9, -1};

            if (isLeaf[u]) {
                Best selfCand{0, u, -1};
                relaxBest(selfCand, best, *(new Best{-1, (int)1e9, -1}));
            }

            Best mx1{-1, (int)1e9, -1}, mx2{-1, (int)1e9, -1};
            if (isLeaf[u]) {
                relaxBest({0, u, -1}, mx1, mx2);
            }
            for (int v : children[u]) {
                relaxBest({downDist[v] + 1, downLeaf[v], v}, mx1, mx2);
            }
            downDist[u] = mx1.dist;
            downLeaf[u] = mx1.leaf;
        }

        vector<int> upDist(n + 1, -1), upLeaf(n + 1, (int)1e9);

        vector<int> parentToChildLeaf(n + 1, -1);

        for (int u : order) {
            Best mx1{-1, (int)1e9, -1}, mx2{-1, (int)1e9, -1};

            if (isLeaf[u]) {
                relaxBest({0, u, -1}, mx1, mx2);
            }
            if (upDist[u] != -1) {
                relaxBest({upDist[u], upLeaf[u], -1}, mx1, mx2);
            }
            for (int v : children[u]) {
                relaxBest({downDist[v] + 1, downLeaf[v], v}, mx1, mx2);
            }

            for (int v : children[u]) {
                Best bestExcl = (mx1.src != v ? mx1 : mx2);
                parentToChildLeaf[v] = bestExcl.leaf;
                upLeaf[v] = bestExcl.leaf;
                upDist[v] = bestExcl.dist + 1;
            }
        }

        vector<int> leafId(n + 1, -1), leafNodes;
        leafNodes.reserve(n);
        for (int i = 1; i <= n; ++i) {
            if (isLeaf[i]) {
                leafId[i] = (int)leafNodes.size();
                leafNodes.push_back(i);
            }
        }

        int L = (int)leafNodes.size();
        vector<ll> leafSum(L, 0);

        for (int u = 2; u <= n; ++u) {
            int lf = downLeaf[u];
            leafSum[leafId[lf]] += a[u];
        }

        TopKSum ds(k - 1);
        for (int i = 0; i < L; ++i)
            ds.insertValue(leafSum[i]);

        auto modifyLeaf = [&](int leafNode, ll delta) {
            int id = leafId[leafNode];
            ds.eraseValue(leafSum[id]);
            leafSum[id] += delta;
            ds.insertValue(leafSum[id]);
        };

        ll answer = 0;

        struct Frame {
            int u;
            int idx;
        };

        vector<Frame> st;
        st.push_back({1, 0});

        while (!st.empty()) {
            int u = st.back().u;
            int &idx = st.back().idx;

            if (idx == 0) {
                answer = max(answer, a[u] + ds.query());
            }

            if (idx < (int)children[u].size()) {
                int v = children[u][idx++];
                modifyLeaf(downLeaf[v], -a[v]);
                modifyLeaf(parentToChildLeaf[v], +a[u]);

                st.push_back({v, 0});
            } else {
                st.pop_back();
                if (!st.empty()) {
                    int p = st.back().u;
                    int v = u;
                    modifyLeaf(parentToChildLeaf[v], -a[p]);
                    modifyLeaf(downLeaf[v], +a[v]);
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}