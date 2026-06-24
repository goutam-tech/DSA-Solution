#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> t(n), d(n);
    for(int i = 0; i < n; i++) cin >> t[i] >> d[i];

    const long long INF = 1e18;
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
    dp[0][0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            if(dp[i][j] == INF) continue;

            if(j + 1 <= k)
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);

            long long start = max(dp[i][j], (long long)t[i]);
            dp[i + 1][j] = min(dp[i + 1][j], start + d[i]);
        }
    }

    long long ans = 0;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            if(dp[i][j] == INF) continue;

            // long long freeStart = dp[i][j];
            // long long freeEnd = (i == n) ? 86400 : (long long)t[i] - 1;

            long long freeStart = max(dp[i][j], 1LL);
            long long freeEnd = (i == n) ? 86400LL : (long long)t[i] - 1;
            
            if(freeEnd >= freeStart)
                ans = max(ans, freeEnd - freeStart + 1);
        }
    }

    cout << ans << "\n";
}