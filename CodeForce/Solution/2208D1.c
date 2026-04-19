#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int reach[505][505];
int n;

int main() {
    char t_buf[32];
    char *end;
    long t_long;
    if (!fgets(t_buf, sizeof(t_buf), stdin)) return 1;
    errno = 0;
    t_long = strtol(t_buf, &end, 10);
    if (end == t_buf || (*end != '\n' && *end != '\0')) { fprintf(stderr, "Invalid input for t\n"); return 1; }
    if ((t_long == LONG_MIN || t_long == LONG_MAX) && errno == ERANGE) { fprintf(stderr, "Out of range for t\n"); return 1; }
    if (t_long < INT_MIN || t_long > INT_MAX) { fprintf(stderr, "t out of int range\n"); return 1; }
    int t = (int)t_long;

    while (t-- > 0) {
        char n_buf[32];
        long n_long;
        if (!fgets(n_buf, sizeof(n_buf), stdin)) return 1;
        errno = 0;
        n_long = strtol(n_buf, &end, 10);
        if (end == n_buf || (*end != '\n' && *end != '\0')) { fprintf(stderr, "Invalid input for n\n"); return 1; }
        if ((n_long == LONG_MIN || n_long == LONG_MAX) && errno == ERANGE) { fprintf(stderr, "Out of range for n\n"); return 1; }
        if (n_long < INT_MIN || n_long > INT_MAX) { fprintf(stderr, "n out of int range\n"); return 1; }
        n = (int)n_long;
        
        char row[505];
        for (int i = 0; i < n; i++) {
            scanf("%s", row);
            for (int j = 0; j < n; j++)
                reach[i][j] = row[j] - '0';
        }

        int valid = 1;

        for (int i = 0; i < n && valid; i++)
            if (!reach[i][i]) valid = 0;

        for (int i = 0; i < n && valid; i++)
            for (int j = 0; j < n && valid; j++)
                if (i != j && reach[i][j] && reach[j][i])
                    valid = 0;

        for (int i = 0; i < n && valid; i++)
            for (int j = 0; j < n && valid; j++)
                for (int k = 0; k < n && valid; k++)
                    if (reach[i][j] && reach[j][k] && !reach[i][k])
                        valid = 0;

        if (!valid) { printf("No\n"); continue; }

        int ex[505], ey[505], ecnt = 0;

        for (int u = 0; u < n && valid; u++) {
            for (int v = 0; v < n; v++) {
                if (u == v) continue;
                if (!reach[u][v]) continue;
                if (reach[v][u]) continue;

                int direct = 1;
                for (int w = 0; w < n; w++) {
                    if (w == u || w == v) continue;
                    if (reach[u][w] && reach[w][v]) {
                        direct = 0;
                        break;
                    }
                }
                if (direct) {
                    ex[ecnt] = u + 1;
                    ey[ecnt] = v + 1;
                    ecnt++;
                }
            }
        }

        if (ecnt != n - 1) { printf("No\n"); continue; }

        int parent[505];
        for (int i = 0; i < n; i++) parent[i] = i;

        #define FIND(x) ({ int _x = (x); while (parent[_x] != _x) _x = parent[_x] = parent[parent[_x]]; _x; })

        int tree_valid = 1;
        for (int i = 0; i < ecnt; i++) {
            int u = ex[i] - 1, v = ey[i] - 1;
            int pu = FIND(u), pv = FIND(v);
            if (pu == pv) { tree_valid = 0; break; }
            parent[pu] = pv;
        }

        if (tree_valid) {
            int root = FIND(0);
            for (int i = 1; i < n; i++)
                if (FIND(i) != root) { tree_valid = 0; break; }
        }

        if (!tree_valid) { printf("No\n"); continue; }

        int adj[505][505], outdeg[505];
        memset(outdeg, 0, sizeof(outdeg));
        memset(adj, 0, sizeof(adj));
        for (int i = 0; i < ecnt; i++) {
            int u = ex[i]-1, v = ey[i]-1;
            adj[u][outdeg[u]++] = v;
        }

        int comp_reach[505][505];
        memset(comp_reach, 0, sizeof(comp_reach));
        for (int i = 0; i < n; i++) comp_reach[i][i] = 1;

        int queue[505];
        for (int src = 0; src < n; src++) {
            int head = 0, tail = 0;
            queue[tail++] = src;
            while (head < tail) {
                int u = queue[head++];
                for (int d = 0; d < outdeg[u]; d++) {
                    int v = adj[u][d];
                    if (!comp_reach[src][v]) {
                        comp_reach[src][v] = 1;
                        queue[tail++] = v;
                    }
                }
            }
        }

        int match = 1;
        for (int i = 0; i < n && match; i++)
            for (int j = 0; j < n && match; j++)
                if (comp_reach[i][j] != reach[i][j])
                    match = 0;

        if (!match) { printf("No\n"); continue; }

        printf("Yes\n");
        for (int i = 0; i < ecnt; i++)
            printf("%d %d\n", ex[i], ey[i]);
    }

    return 0;
}