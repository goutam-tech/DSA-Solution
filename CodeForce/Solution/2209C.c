#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int query(int, int);

int main() {
    char buf[64];
    char *end;
    long lt;
    int t;
    errno = 0;
    if (!fgets(buf, sizeof(buf), stdin)) return 0;
    lt = strtol(buf, &end, 10);
    if (end == buf || (*end != '\n' && *end != '\0') || errno == ERANGE || lt < INT_MIN || lt > INT_MAX) {
        fprintf(stderr, "Invalid input for t\n");
        return 1;
    }
    t = (int)lt;

    while (t-- > 0) {
        int n;
        errno = 0;
        if (!fgets(buf, sizeof(buf), stdin)) return 0;
        lt = strtol(buf, &end, 10);
        if (end == buf || (*end != '\n' && *end != '\0') || errno == ERANGE || lt < INT_MIN || lt > INT_MAX) {
            fprintf(stderr, "Invalid input for n\n");
            return 1;
        }
        n = (int)lt;

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