
#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int parent[MAX], sz[MAX];
int A[MAX], result[MAX];
int vertices[MAX], values[MAX];

int cmp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y)
        return -1;
    if (x > y)
        return 1;
    return 0;
}

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
}

int main() {
    int n, m, u, v;

    if (scanf("%d %d", &n, &m) != 2)
        return 1;

    if (n < 1 || n >= MAX || m < 0) {
        printf("Invalid input\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        if (scanf("%d", &A[i]) != 1)
            return 1;

        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        if (scanf("%d %d", &u, &v) != 2)
            return 1;

        if (u < 1 || u > n || v < 1 || v > n) {
            printf("Invalid edge\n");
            return 1;
        }

        unite(u, v);
    }

    for (int i = 1; i <= n; i++)
        result[i] = A[i];

    for (int root = 1; root <= n; root++) {
        if (find(root) != root)
            continue;

        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (find(i) == root) {
                vertices[count] = i;
                values[count] = A[i];
                count++;
            }
        }

        qsort(vertices, count, sizeof(int), cmp);
        qsort(values, count, sizeof(int), cmp);

        for (int i = 0; i < count; i++)
            result[vertices[i]] = values[i];
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", result[i]);

    printf("\n");
    return 0;
}