#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main() {
    char buf[64];
    char *endptr;
    long temp;
    if (!fgets(buf, sizeof(buf), stdin)) {
        (void)fprintf(stderr, "Error reading t\n");
        return 1;
    }
    errno = 0;
    temp = strtol(buf, &endptr, 10);
    if (endptr == buf || (*endptr != '\n' && *endptr != '\0') ||
        (errno == ERANGE && (temp == LONG_MAX || temp == LONG_MIN)) ||
        temp < INT_MIN || temp > INT_MAX) {
        (void)fprintf(stderr, "Invalid integer input for t\n");
        return 1;
    }
    int t = (int)temp;

    while (t-- > 0) {
        if (!fgets(buf, sizeof(buf), stdin)) {
            (void)fprintf(stderr, "Error reading n\n");
            return 1;
        }
        errno = 0;
        temp = strtol(buf, &endptr, 10);
        if (endptr == buf || (*endptr != '\n' && *endptr != '\0') ||
            (errno == ERANGE && (temp == LONG_MAX || temp == LONG_MIN)) ||
            temp < INT_MIN || temp > INT_MAX) {
            (void)fprintf(stderr, "Invalid integer input for n\n");
            return 1;
        }
        int n = (int)temp;

        int c[100005], p[100005];
        for (int i = 0; i < n; i++) {
            if (!fgets(buf, sizeof(buf), stdin)) {
                (void)fprintf(stderr, "Error reading c[i] and p[i]\n");
                return 1;
            }
            char *ptr = buf;
            errno = 0;
            long val1 = strtol(ptr, &endptr, 10);
            if (endptr == ptr || (errno == ERANGE && (val1 == LONG_MAX || val1 == LONG_MIN)) ||
                val1 < INT_MIN || val1 > INT_MAX) {
                (void)fprintf(stderr, "Invalid input for c[%d]\n", i);
                return 1;
            }
            ptr = endptr;
            errno = 0;
            long val2 = strtol(ptr, &endptr, 10);
            if (endptr == ptr || (errno == ERANGE && (val2 == LONG_MAX || val2 == LONG_MIN)) ||
                val2 < INT_MIN || val2 > INT_MAX) {
                (void)fprintf(stderr, "Invalid input for p[%d]\n", i);
                return 1;
            }
            c[i] = (int)val1;
            p[i] = (int)val2;
        }
        
        double F = 0.0;
        for (int i = n - 1; i >= 0; i--) {
            double complete = c[i] + F * (1.0 - p[i] / 100.0);
            double skip = F;
            F = (complete > skip) ? complete : skip;
        }

        (void)printf("%.10f\n", F);
    }

    return 0;
}