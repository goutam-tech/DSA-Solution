#include <stdio.h>

int query(int i, int j) {
    printf("? %d %d\n", i, j);
    fflush(stdout);
    int r;
    scanf("%d", &r);
    return r;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int ans = 2 * n;
        int found = 0;

        int r;

        r = query(1, 2);
        if (r == -1) return 0;
        if (r == 1) { printf("! 1\n"); fflush(stdout); found = 1; goto next; }

        r = query(1, 3);
        if (r == -1) return 0;
        if (r == 1) { printf("! 1\n"); fflush(stdout); found = 1; goto next; }

        r = query(2, 3);
        if (r == -1) return 0;
        if (r == 1) { printf("! 2\n"); fflush(stdout); found = 1; goto next; }

        for (int k = 1; k <= n - 2 && !found; k++) {
            int i = 2 * k + 2;
            int j = 2 * k + 3;
            r = query(i, j);
            if (r == -1) return 0;
            if (r == 1) { printf("! %d\n", i); fflush(stdout); found = 1; goto next; }
        }

        printf("! %d\n", ans);
        fflush(stdout);

        next:;
    }

    return 0;
}