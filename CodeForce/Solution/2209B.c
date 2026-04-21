#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main() {
    char buf[64];
    char *end;
    errno = 0;
    long t_long;
    int t;
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        (void) fprintf(stderr, "Error reading number of test cases\n");
        return 1;
    }
    errno = 0;
    t_long = strtol(buf, &end, 10);
    if (end == buf || (*end != '\n' && *end != '\0')) {
        (void) fprintf(stderr, "Invalid number format for test cases\n");
        return 1;
    }
    if ((errno == ERANGE && (t_long == LONG_MAX || t_long == LONG_MIN)) || t_long < INT_MIN || t_long > INT_MAX) {
        (void) fprintf(stderr, "Test cases number out of range\n");
        return 1;
    }
    t = (int)t_long;

    while (t-- > 0) {
        long n_long;
        int n;
        if (fgets(buf, sizeof(buf), stdin) == NULL) {
            (void) fprintf(stderr, "Error reading n\n");
            return 1;
        }
        errno = 0;
        n_long = strtol(buf, &end, 10);
        if (end == buf || (*end != '\n' && *end != '\0')) {
            (void) fprintf(stderr, "Invalid number format for n\n");
            return 1;
        }
        if ((errno == ERANGE && (n_long == LONG_MAX || n_long == LONG_MIN)) || n_long < INT_MIN || n_long > INT_MAX) {
            (void) fprintf(stderr, "n out of range\n");
            return 1;
        }
        n = (int)n_long;

        long long a[5000];
        for (int i = 0; i < n; i++) {
            if (fgets(buf, sizeof(buf), stdin) == NULL) {
                (void) fprintf(stderr, "Error reading a[%d]\n", i);
                return 1;
            }
            errno = 0;
            long long val = strtoll(buf, &end, 10);
            if (end == buf || (*end != '\n' && *end != '\0')) {
                (void) fprintf(stderr, "Invalid number format for a[%d]\n", i);
                return 1;
            }
            if ((errno == ERANGE && (val == LLONG_MAX || val == LLONG_MIN)) || val < LLONG_MIN || val > LLONG_MAX) {
                (void) fprintf(stderr, "a[%d] out of range\n", i);
                return 1;
            }
            a[i] = val;
        }

        for (int i = 0; i < n; i++) {
            int less = 0, greater = 0;
            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[i]) less++;
                if (a[j] > a[i]) greater++;
            }
            int best = less > greater ? less : greater;
            (void) printf("%d", best);
            if (i < n - 1) (void) printf(" ");
        }
        (void) printf("\n");
    }

    return 0;
}