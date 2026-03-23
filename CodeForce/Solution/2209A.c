#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    long long x = *(long long *)a, y = *(long long *)b;
    return (x > y) - (x < y);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        long long c, k;
        scanf("%d %lld %lld", &n, &c, &k);

        long long a[100];
        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]);

        qsort(a, n, sizeof(long long), cmp);

        long long rem = k;
        int changed = 1;
        while (changed) {
            changed = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] < 0) continue;
                if (a[i] <= c) {
                    long long boost = c - a[i];
                    if (boost > rem) boost = rem;
                    rem -= boost;
                    c += a[i] + boost;
                    a[i] = -1;
                    changed = 1;
                }
            }
        }

        for (int i = 0; i < n && rem > 0; i++) {
            if (a[i] == 0) {
                a[i] = 1;
                rem--;
            }
        }

        long long b[100];
        int m = 0;
        for (int i = 0; i < n; i++)
            if (a[i] >= 0) b[m++] = a[i];
        qsort(b, m, sizeof(long long), cmp);

        changed = 1;
        while (changed) {
            changed = 0;
            for (int i = 0; i < m; i++) {
                if (b[i] < 0) continue;
                if (b[i] <= c) {
                    long long boost = c - b[i];
                    if (boost > rem) boost = rem;
                    rem -= boost;
                    c += b[i] + boost;
                    b[i] = -1;
                    changed = 1;
                }
            }
        }

        printf("%lld\n", c);
    }

    return 0;
}