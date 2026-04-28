#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main() {
    int t;
    char buf[32];
    char *end;
    errno = 0;
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        (void)fprintf(stderr, "Input error\n");
        return EXIT_FAILURE;
    }
    long tmp = strtol(buf, &end, 10);
    if (end == buf || (*end != '\n' && *end != '\0')) {
        (void)fprintf(stderr, "Invalid integer input\n");
        return EXIT_FAILURE;
    }
    if ((errno == ERANGE && (tmp == LONG_MAX || tmp == LONG_MIN)) || tmp > INT_MAX || tmp < INT_MIN) {
        (void)fprintf(stderr, "Integer out of range\n");
        return EXIT_FAILURE;
    }
    t = (int)tmp;
    
    while (t-- > 0) {
        int n;
        errno = 0;
        if (fgets(buf, sizeof(buf), stdin) == NULL) {
            (void)fprintf(stderr, "Input error\n");
            return EXIT_FAILURE;
        }
        tmp = strtol(buf, &end, 10);
        if (end == buf || (*end != '\n' && *end != '\0')) {
            (void)fprintf(stderr, "Invalid integer input\n");
            return EXIT_FAILURE;
        }
        if ((errno == ERANGE && (tmp == LONG_MAX || tmp == LONG_MIN)) || tmp > INT_MAX || tmp < INT_MIN) {
            (void)fprintf(stderr, "Integer out of range\n");
            return EXIT_FAILURE;
        }
        n = (int)tmp;
        
        int freq[10001];
        (void)memset(freq, 0, sizeof(freq));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                errno = 0;
                if (fgets(buf, sizeof(buf), stdin) == NULL) {
                    (void)fprintf(stderr, "Input error\n");
                    return EXIT_FAILURE;
                }
                tmp = strtol(buf, &end, 10);
                if (end == buf || (*end != '\n' && *end != '\0')) {
                    (void)fprintf(stderr, "Invalid integer input\n");
                    return EXIT_FAILURE;
                }
                if ((errno == ERANGE && (tmp == LONG_MAX || tmp == LONG_MIN)) || tmp > INT_MAX || tmp < INT_MIN) {
                    (void)fprintf(stderr, "Integer out of range\n");
                    return EXIT_FAILURE;
                }
                x = (int)tmp;
                freq[x]++;
            }
        }
        
        if (n == 1) {
            (void)printf("NO\n");
            continue;
        }
        
        int possible = 1;
        int limit = n * (n - 1);
        
        for (int c = 1; c <= n * n; c++) {
            if (freq[c] > limit) {
                possible = 0;
                break;
            }
        }
        
        (void)printf(possible ? "YES\n" : "NO\n");
    }
    return 0;
}