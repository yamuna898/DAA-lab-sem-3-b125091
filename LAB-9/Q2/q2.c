#include <stdio.h>
#include <string.h>

struct Node {
    char ch;
    int freq;
    int left;
    int right;
};

void printCodes(struct Node tree[], int index, char code[], int depth) {

    if (tree[index].left == -1 && tree[index].right == -1) {
        code[depth] = '\0';
        printf("%c : %s\n", tree[index].ch, code);
        return;
    }

    if (tree[index].left != -1) {
        code[depth] = '0';
        printCodes(tree, tree[index].left, code, depth + 1);
    }

    if (tree[index].right != -1) {
        code[depth] = '1';
        printCodes(tree, tree[index].right, code, depth + 1);
    }
}

int main() {

    int n;

    printf("Enter number of symbols: ");
    scanf("%d", &n);

    struct Node tree[100];

    for (int i = 0; i < n; i++) {
        printf("Enter character and frequency: ");
        scanf(" %c %d", &tree[i].ch, &tree[i].freq);

        tree[i].left = -1;
        tree[i].right = -1;
    }

    int total = n;

    while (1) {

        int first = -1;
        int second = -1;

        for (int i = 0; i < total; i++) {

            if (tree[i].freq == -1)
                continue;

            if (first == -1 || tree[i].freq < tree[first].freq) {
                second = first;
                first = i;
            }
            else if (second == -1 || tree[i].freq < tree[second].freq) {
                second = i;
            }
        }

        if (second == -1)
            break;

        tree[total].ch = '#';
        tree[total].freq = tree[first].freq + tree[second].freq;
        tree[total].left = first;
        tree[total].right = second;

        tree[first].freq = -1;
        tree[second].freq = -1;

        total++;
    }

    char code[100];

    printf("\nHuffman Codes:\n");

    printCodes(tree, total - 1, code, 0);

    return 0;
}