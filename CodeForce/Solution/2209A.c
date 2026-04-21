#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int cmp(const void *a, const void *b) {
    long long x = *(long long *)a, y = *(long long *)b;
    return (x > y) - (x < y);
}

int main() {
    char buf[64];
    char *end;
    errno = 0;
    if (!fgets(buf, sizeof(buf), stdin)) {
        (void)fprintf(stderr, "Error reading number of test cases
");
        return 1;
    }
    long t_long = strtol(buf, &end, 10);
    if (end == buf || (*end != '\n' && *end != '\0')) {
        (void)fprintf(stderr, "Invalid number of test cases
");
        return 1;
    }
    if ((t_long == LONG_MIN || t_long == LONG_MAX) && errno == ERANGE) {
        (void)fprintf(stderr, "Test cases out of range
");
        return 1;
    }
    int t = (int)t_long;

    while (t-- > 0) {
        if (!fgets(buf, sizeof(buf), stdin)) {
            (void)fprintf(stderr, "Error reading parameters
");
            return 1;
        }
        char *p = buf;
        errno = 0;
        long n_long = strtol(p, &end, 10);
        if (end == p) {
            (void)fprintf(stderr, "Invalid n
");
            return 1;
        }
        p = end;
        errno = 0;
        long c_long = strtol(p, &end, 10);
        if (end == p) {
            (void)fprintf(stderr, "Invalid c
");
            return 1;
        }
        p = end;
        errno = 0;
        long k_long = strtol(p, &end, 10);
        if (end == p) {
            (void)fprintf(stderr, "Invalid k
");
            return 1;
        }
        int n = (int)n_long;
        long long c = (long long)c_long;
        long long k = (long long)k_long;

        long long a[100];
        for (int i = 0; i < n; i++) {
            if (!fgets(buf, sizeof(buf), stdin)) {
                (void)fprintf(stderr, "Error reading array element
");
                return 1;
            }
            errno = 0;
            long long ai = strtoll(buf, &end, 10);
            if (end == buf || (*end != '\n' && *end != '\0')) {
                (void)fprintf(stderr, "Invalid array element
");
                return 1;
            }
            if ((ai == LLONG_MIN || ai == LLONG_MAX) && errno == ERANGE) {
                (void)fprintf(stderr, "Array element out of range
");
                return 1;
            }
            a[i] = ai;
        }

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