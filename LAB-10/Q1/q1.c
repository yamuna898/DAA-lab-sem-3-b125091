
#include <stdio.h>

#define MAX 100005

int parent[MAX], sz[MAX], parity[MAX];

int find(int x) {
    if (parent[x] != x) {
        int p = parent[x];
        parent[x] = find(p);
        parity[x] ^= parity[p];
    }
    return parent[x];
}

int addEdge(int u, int v) {
    int ru = find(u);
    int pu = parity[u];

    int rv = find(v);
    int pv = parity[v];

    if (ru == rv)
        return pu != pv;

    if (sz[ru] < sz[rv]) {
        int temp = ru;
        ru = rv;
        rv = temp;
    }

    parent[rv] = ru;
    parity[rv] = pu ^ pv ^ 1;
    sz[ru] += sz[rv];

    return 1;
}

int main() {
    int V, E, u, v;

    scanf("%d %d", &V, &E);

    if (V >= MAX || V < 1 || E < 0) {
        printf("Invalid input\n");
        return 1;
    }

    for (int i = 1; i <= V; i++) {
        parent[i] = i;
        sz[i] = 1;
        parity[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);

        if (u < 1 || u > V || v < 1 || v > V) {
            printf("Invalid edge\n");
            return 1;
        }

        if (addEdge(u, v))
            printf("Edge (%d, %d) accepted\n", u, v);
        else
            printf("Edge (%d, %d) rejected\n", u, v);
    }

    return 0;
}