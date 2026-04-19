#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>

#define MOD 998244353LL
#define MAXN 5005

long long dp[MAXN][MAXN];
long long W[MAXN][MAXN];
int X[MAXN];
int n;

typedef struct { int l, r, base; } Interval;
Interval intervals[MAXN];
int n_intervals;

long long seg_dp[MAXN][MAXN];

long long compute_W_interval(int l, int r, int base) {
    if (l > r) return 1LL;
    
    int offset = l - 1;
    int len = r - l + 1;
    
    for (int i = offset; i <= r; i++)
        for (int s = 0; s <= len + 2; s++)
            seg_dp[i][s] = 0;
    
    seg_dp[offset][1] = 1;
    
    for (int i = l; i <= r; i++) {
        if (X[i] == -1) {
            int acts = i - offset;
            
            if (base == 0) {
                for (int a = 1; a <= acts; a++)
                    seg_dp[i][1] = (seg_dp[i][1] + seg_dp[i-1][a]) % MOD;
            }
            for (int a = 1; a <= acts; a++) {
                if (seg_dp[i-1][a] == 0) continue;
                int t_start = (base > 0) ? 2 : 2;
                for (int t = t_start; t <= a + 1; t++) {
                    seg_dp[i][t] = (seg_dp[i][t] + seg_dp[i-1][a]) % MOD;
                }
            }
        } else if (X[i] == 0) {
            if (base != 0) return 0LL;
            int acts = i - offset;
            for (int a = 1; a <= acts; a++)
                seg_dp[i][1] = (seg_dp[i][1] + seg_dp[i-1][a]) % MOD;
        } else {
            int j = X[i];
            if (j < base) return 0LL;
            if (j >= i) return 0LL;
            
            if (j == base) {
                int acts = i - offset;
                for (int a = 1; a <= acts; a++)
                    seg_dp[i][2] = (seg_dp[i][2] + seg_dp[i-1][a]) % MOD;
            } else {
                long long W_nested = compute_W_interval(j + 1, i - 1, j);
                if (W_nested == 0 && j + 1 <= i - 1) {
                    
                }
                
                int max_a_j = j - offset;
                for (int a_j = 1; a_j <= max_a_j; a_j++) {
                    if (seg_dp[j][a_j] == 0) continue;
                    int new_act = a_j + 1;
                    seg_dp[i][new_act] = (seg_dp[i][new_act] + seg_dp[j][a_j] % MOD * W_nested) % MOD;
                }
            }
        }
    }
    
    long long total = 0;
    int acts = r - offset + 1;
    for (int a = 1; a <= acts; a++)
        total = (total + seg_dp[r][a]) % MOD;
    return total;
}

void solve() {
    char buf[64];
    char *end;
    size_t len;
    /* read n */
    if (!fgets(buf, sizeof(buf), stdin)) { printf("0\n"); return; }
    len = strlen(buf);
    if (len > 0 && buf[len-1] == '\n') buf[len-1] = '\0';
    errno = 0;
    long n_long = strtol(buf, &end, 10);
    if (end == buf || *end != '\0' || errno == ERANGE || n_long < 0 || n_long > INT_MAX) { printf("0\n"); return; }
    int n = (int)n_long;
    for (int i = 1; i <= n; i++) {
        if (!fgets(buf, sizeof(buf), stdin)) { printf("0\n"); return; }
        len = strlen(buf);
        if (len > 0 && buf[len-1] == '\n') buf[len-1] = '\0';
        errno = 0;
        long x_long = strtol(buf, &end, 10);
        if (end == buf || *end != '\0' || errno == ERANGE || x_long < INT_MIN || x_long > INT_MAX) { printf("0\n"); return; }
        X[i] = (int)x_long;
    }

    if (X[1] != -1 && X[1] != 0) { printf("0\n"); return; }
    X[1] = 0;

    for (int i = 1; i <= n; i++) {
        if (X[i] != -1) {
            if (X[i] < 0 || X[i] >= i) { printf("0\n"); return; }
        }
    }
    
    for (int r = 1; r <= n; r++) {
        if (X[r] > 0) {
            int j = X[r];
            for (int k = j + 1; k < r; k++) {
                if (X[k] != -1 && X[k] < j) { printf("0\n"); return; }
            }
        }
    }
    
    long long ans = compute_W_interval(1, n, 0);
    printf("%lld\n", ans);
}

int main() {
    int t;
    char buf[64];
    char *end = NULL;
    long val;
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        fprintf(stderr, "Failed to read input for test cases\n");
        return 1;
    }
    errno = 0;
    val = strtol(buf, &end, 10);
    if (end == buf || (*end != '\n' && *end != '\0')) {
        fprintf(stderr, "Invalid number of test cases: %s", buf);
        return 1;
    }
    if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN)) || val > INT_MAX || val < INT_MIN) {
        fprintf(stderr, "Test case count out of range: %ld\n", val);
        return 1;
    }
    t = (int)val;
    
    while (t-- > 0) solve();
    return 0;
}