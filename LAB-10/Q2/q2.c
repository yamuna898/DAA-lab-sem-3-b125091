
#include <stdio.h>

#define MAX 100005

int parent[MAX], sz[MAX], land[MAX];
int R, C, islands;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

int unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return 0;

    if (sz[a] < sz[b]) {
        int temp = a;
        a = b;
        b = temp;
    }

    parent[b] = a;
    sz[a] += sz[b];

    return 1;
}

void addLand(int r, int c) {
    int id = r * C + c;

    if (land[id]) {
        printf("%d ", islands);
        return;
    }

    land[id] = 1;
    islands++;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < R &&
            nc >= 0 && nc < C) {
            int nid = nr * C + nc;

            if (land[nid] && unite(id, nid))
                islands--;
        }
    }

    printf("%d ", islands);
}

int main() {
    int K, r, c;

    if (scanf("%d %d %d", &R, &C, &K) != 3)
        return 1;

    if (R <= 0 || C <= 0 || K < 0 ||
        (long long)R * C > MAX) {
        printf("Invalid input\n");
        return 1;
    }

    for (int i = 0; i < R * C; i++) {
        parent[i] = i;
        sz[i] = 1;
        land[i] = 0;
    }

    islands = 0;

    for (int i = 0; i < K; i++) {
        if (scanf("%d %d", &r, &c) != 2)
            return 1;

        if (r < 0 || r >= R || c < 0 || c >= C) {
            printf("\nInvalid coordinate\n");
            return 1;
        }

        addLand(r, c);
    }

    printf("\n");
    return 0;
}