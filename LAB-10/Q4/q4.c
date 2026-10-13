
#include <stdio.h>

#define MAX 100005
#define MAXE 200005

int parent[MAX], sz[MAX], active[MAX];
int head[MAX], to[MAXE], next[MAXE];
int edgeCount = 0;

long long weight[MAX], sum[MAX], ans[MAX];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void addEdge(int u, int v) {
    to[edgeCount] = v;
    next[edgeCount] = head[u];
    head[u] = edgeCount++;

    to[edgeCount] = u;
    next[edgeCount] = head[v];
    head[v] = edgeCount++;
}

long long unite(int a, int b, long long best) {
    a = find(a);
    b = find(b);

    if (a == b)
        return best;

    if (sz[a] < sz[b]) {
        int temp = a;
        a = b;
        b = temp;
    }

    parent[b] = a;
    sz[a] += sz[b];
    sum[a] += sum[b];

    if (sum[a] > best)
        best = sum[a];

    return best;
}

int main() {
    int V, E, u, v;
    int P[MAX];

    if (scanf("%d %d", &V, &E) != 2)
        return 1;

    if (V < 1 || V >= MAX || E < 0 ||
        2LL * E > MAXE) {
        printf("Invalid input\n");
        return 1;
    }

    for (int i = 1; i <= V; i++) {
        if (scanf("%lld", &weight[i]) != 1)
            return 1;

        parent[i] = i;
        sz[i] = 1;
        head[i] = -1;
    }

    for (int i = 0; i < E; i++) {
        if (scanf("%d %d", &u, &v) != 2)
            return 1;

        if (u < 1 || u > V || v < 1 || v > V) {
            printf("Invalid edge\n");
            return 1;
        }

        addEdge(u, v);
    }

    for (int i = 1; i <= V; i++) {
        if (scanf("%d", &P[i]) != 1)
            return 1;

        if (P[i] < 1 || P[i] > V) {
            printf("Invalid permutation\n");
            return 1;
        }

        for (int j = 1; j < i; j++) {
            if (P[i] == P[j]) {
                printf("Invalid permutation\n");
                return 1;
            }
        }
    }

    long long best = 0;

    for (int i = V; i >= 1; i--) {
        ans[i] = best;

        int x = P[i];
        active[x] = 1;
        sum[x] = weight[x];

        if (sum[x] > best)
            best = sum[x];

        for (int e = head[x]; e != -1; e = next[e]) {
            int y = to[e];

            if (active[y])
                best = unite(x, y, best);
        }
    }

    for (int i = 1; i <= V; i++)
        printf("%lld\n", ans[i]);

    return 0;
}