#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int reach[505][505];
int n;
int read_int(int *out, const char *name) {
    char buf[32];
    char *end;
    long val;
    if (!fgets(buf, sizeof(buf), stdin)) {
        (void)fprintf(stderr, "Missing input for %s\n", name);
        return 1;
    }
    errno = 0;
    val = strtol(buf, &end, 10);
    if (end == buf || (*end != '\n' && *end != '\0')) {
        (void)fprintf(stderr, "Invalid input for %s\n", name);
        return 1;
    }
    if ((val == LONG_MIN || val == LONG_MAX) && errno == ERANGE) {
static int read_matrix(int n, int reach[][505]) {
    char row[505];
    for (int i = 0; i < n; i++) {
        if (scanf("%s", row) != 1) {
            (void)fprintf(stderr, "Failed to read row %d\n", i);
            return 1;
        }
        for (int j = 0; j < n; j++) {
            reach[i][j] = row[j] - '0';
        }
    }
    return 0;
}

static int check_self_loop(int n, int reach[][505]) {
    for (int i = 0; i < n; i++) {
        if (!reach[i][i]) {
            return 0;
        }
    }
    return 1;
}

static int check_symmetry(int n, int reach[][505]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && reach[i][j] && reach[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

static int check_transitive(int n, int reach[][505]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (reach[i][j] && reach[j][k] && !reach[i][k]) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

static int validate_relation(int n, int reach[][505]) {
    return check_self_loop(n, reach)
        && check_symmetry(n, reach)
        && check_transitive(n, reach);
}

int main() {
    int ret = 0;
    int t;
    if (read_int(&t, "t")) {
        ret = 1;
    } else {
        for (int test = 0; test < t; ++test) {
            int n;
            int reach[505][505];
            if (read_int(&n, "n") || read_matrix(n, reach)) {
                ret = 1;
                break;
            }
            int valid = validate_relation(n, reach);
            printf("%s\n", valid ? "YES" : "NO");
        }
    }
    return ret;
}

        if (!valid) { (void)printf("No\n"); continue; }

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