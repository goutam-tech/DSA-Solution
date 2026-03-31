#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        
        int freq[10001];
        memset(freq, 0, sizeof(freq));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                scanf("%d", &x);
                freq[x]++;
            }
        }
        
        if (n == 1) {
            printf("NO\n");
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
        
        printf(possible ? "YES\n" : "NO\n");
    }
    
    return 0;
}