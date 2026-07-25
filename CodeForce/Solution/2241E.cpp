# include <bits/stdc++.h>
using namespace std;

bool isPerfectSquare(long long x){
    long long r = (long long)sqrtl((long double)x);
    while(r * r > x) r--;
    while((r + 1) * (r + 1) <= x) r++;
    return r * r == x;
}

void fair_square(){
    int n;
    cin >> n;
    
    vector<long long> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n + 1, 0), order;
    order.reserve(n);
    vector<long long> sz(n + 1, 1);
    vector<char> visited(n + 1, 0);

    vector<int> stackArr;
    stackArr.reserve(n);
    stackArr.push_back(1);
    visited[1] = 1;
    while(!stackArr.empty()){
        int u = stackArr.back();
        stackArr.pop_back();
        order.push_back(u);
        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = 1;
                parent[v] = u;
                stackArr.push_back(v);
            }
        }
    }

    for(int i = (int)order.size() - 1; i >= 0; i--){
        int u = order[i];
        if(parent[u] != 0) sz[parent[u]] += sz[u];
    }

    long long ans = 0;
    
    for(int x = 1; x <= n; x++){
        if(!isPerfectSquare(a[x])) continue;

        long long P1 = 0, P2 = 0, P3 = 0;
        for(int v : adj[x]){
            long long s = (v == parent[x]) ? (long long)n - sz[x] : sz[v];
            P1 += s;
            P2 += s * s;
            P3 += s * s * s;
        }

        long long m = n - 1;
        long long countA = (m * (m - 1) / 2) - (P2 - P1) / 2;
        long long countB = (P1 * P1 * P1 - 3 * P1 * P2 + 2 * P3) / 6;

        ans += countA + countB;
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        fair_square();
    }
    return 0;
}