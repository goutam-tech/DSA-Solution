#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int c[100005], p[100005];
        for (int i = 0; i < n; i++) scanf("%d %d", &c[i], &p[i]);

        double F = 0.0;
        for (int i = n - 1; i >= 0; i--) {
            double complete = c[i] + F * (1.0 - p[i] / 100.0);
            double skip = F;
            F = (complete > skip) ? complete : skip;
        }

        printf("%.10f\n", F);
    }

    return 0;
}