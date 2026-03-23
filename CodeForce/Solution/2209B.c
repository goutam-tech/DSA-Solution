#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        long long a[5000];
        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]);

        for (int i = 0; i < n; i++) {
            int less = 0, greater = 0;
            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[i]) less++;
                if (a[j] > a[i]) greater++;
            }
            int best = less > greater ? less : greater;
            printf("%d", best);
            if (i < n - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}