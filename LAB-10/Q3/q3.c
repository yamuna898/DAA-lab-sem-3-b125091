
#include <stdio.h>

#define MAX 100005

int parent[MAX], sz[MAX];
long long weight[MAX];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return;

    if (sz[a] < sz[b]) {
        int temp = a;
        a = b;
        b = temp;
    }

    parent[b] = a;
    sz[a] += sz[b];
    weight[a] += weight[b];
}

int main() {
    int V, E, K, u, v;

    if (scanf("%d %d %d", &V, &E, &K) != 3)
        return 1;

    if (V < 1 || V >= MAX || E < 0 || K < 1) {
        printf("Invalid input\n");
        return 1;
    }

    for (int i = 1; i <= V; i++) {
        if (scanf("%lld", &weight[i]) != 1)
            return 1;

        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < E; i++) {
        if (scanf("%d %d", &u, &v) != 2)
            return 1;

        if (u < 1 || u > V || v < 1 || v > V) {
            printf("Invalid edge\n");
            return 1;
        }

        unite(u, v);

        int found = 0;
        long long best = 0;

        for (int j = 1; j <= V; j++) {
            if (find(j) == j && sz[j] <= K) {
                if (!found || weight[j] > best) {
                    best = weight[j];
                    found = 1;
                }
            }
        }

        if (found)
            printf("%lld\n", best);
        else
            printf("No valid component\n");
    }

    return 0;
}