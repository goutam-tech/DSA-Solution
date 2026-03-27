#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 998244353;
const int MAXIN = 5005;

long long dp[MAXIN][MAXIN];
int X[MAXIN];

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> X[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (dp[i][j] == 0) continue;

            if (X[i+1] != -1) {
                if (X[i+1] == 0) {
                    dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % MOD;
                } else if (X[i+1] <= i) {
                    if (j > 0) {
                        dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j]) % MOD;
                    }
                } else if (X[i+1] == i+1) {
                    dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
                }
            } else {
                // Wildcard case: X[i+1] == -1
                if (j > 0) {
                    dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j] * j) % MOD;
                    dp[i+1][j]   = (dp[i+1][j]   + dp[i][j] * j) % MOD; // <-- Fixed line
                }
                dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % MOD;
            }
        }
    }

    cout << dp[n][0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}