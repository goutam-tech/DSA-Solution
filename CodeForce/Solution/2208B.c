#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void solve(int t){
    char buf[256];
    char *end;
    long tmp;
    int n, k, p, m;

    if (!fgets(buf, sizeof buf, stdin)){
        (void)fprintf(stderr, "Input error
");
        return;
    }
    char *ptr = buf;
    errno = 0;
    tmp = strtol(ptr, &end, 10);
    if (errno == ERANGE || end == ptr || (*end != ' ' && *end != '\t' && *end != '\n' && *end != '\0')){
        (void)fprintf(stderr, "Invalid input for n
");
        return;
    }
    n = (int)tmp;
    ptr = end;
    errno = 0;
    tmp = strtol(ptr, &end, 10);
    if (errno == ERANGE || end == ptr || (*end != ' ' && *end != '\t' && *end != '\n' && *end != '\0')){
        (void)fprintf(stderr, "Invalid input for k
");
        return;
    }
    k = (int)tmp;
    ptr = end;
    errno = 0;
    tmp = strtol(ptr, &end, 10);
    if (errno == ERANGE || end == ptr || (*end != ' ' && *end != '\t' && *end != '\n' && *end != '\0')){
        (void)fprintf(stderr, "Invalid input for p
");
        return;
    }
    p = (int)tmp;
    ptr = end;
    errno = 0;
    tmp = strtol(ptr, &end, 10);
    if (errno == ERANGE || end == ptr || (*end != ' ' && *end != '\t' && *end != '\n' && *end != '\0')){
        (void)fprintf(stderr, "Invalid input for m
");
        return;
    }
    m = (int)tmp;

    int a[5000];
    for (int i = 0; i < n; i++){
        if (!fgets(buf, sizeof buf, stdin)){
            (void)fprintf(stderr, "Input error
");
            return;
        }
        errno = 0;
        tmp = strtol(buf, &end, 10);
        if (errno == ERANGE || end == buf || (*end != '\n' && *end != '\0')){
            (void)fprintf(stderr, "Invalid input for a[%d]
", i);
            return;
        }
        a[i] = (int)tmp;
    }

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
    char line[64];
    char *end;
    long temp;
    if (fgets(line, sizeof(line), stdin) == NULL) {
        (void)fprintf(stderr, "Error reading test case count\n");
        return EXIT_FAILURE;
    }
    errno = 0;
    temp = strtol(line, &end, 10);
    if (end == line || (*end != '\0' && *end != '\n')) {
        (void)fprintf(stderr, "Invalid number of test cases: %s", line);
        return EXIT_FAILURE;
    }
    if ((errno == ERANGE && (temp == LONG_MAX || temp == LONG_MIN))
        || temp > INT_MAX || temp < INT_MIN) {
        (void)fprintf(stderr, "Test case count out of range: %ld\n", temp);
        return EXIT_FAILURE;
    }
    int t = (int)temp;
    
    while (t-- > 0) {
        solve(t);
    }
    return 0;
}