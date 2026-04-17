#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void solve(int t){
    int n, k, p, m;
    scanf("%d %d %d %d", &n, &k, &p, &m);
    int a[5000];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int win_cost = a[p - 1];
    long long setup_cost = 0;
    int setup_need = (p > k) ? (p - k) : 0;
    if (setup_need > 0) {
        int before[5000];
        for (int i = 0; i < p - 1; i++) before[i] = a[i];
        qsort(before, p - 1, sizeof(int), cmp);
        for (int i = 0; i < setup_need; i++) setup_cost += before[i];
    }
    long long cycle_cost = 0;
    if (k < n) {
        int others[5000];
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (i != p - 1) others[cnt++] = a[i];
        qsort(others, cnt, sizeof(int), cmp);
        int take = (k - 1 < cnt) ? k - 1 : cnt;
        for (int i = 0; i < take; i++) cycle_cost += others[i];
    }
    int ans = 0;
    for (int x = 1; (long long)x * win_cost <= (long long)m; x++) {
        long long cost = setup_cost
                        + (long long)x * win_cost
                        + (long long)(x - 1) * cycle_cost;
        if (cost <= m) ans = x;
        else break;
    }
    printf("%d\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve(t);
    }
    return 0;
}