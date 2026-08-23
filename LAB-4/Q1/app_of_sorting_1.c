#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    int number;
    char color[10];
} Item;

    void sortByColorThreeBuckets(Item arr[], int n) {
    Item *red = (Item *)malloc(n * sizeof(Item));
    Item *blue = (Item *)malloc(n * sizeof(Item));
    Item *yellow = (Item *)malloc(n * sizeof(Item));
    
    int r = 0, b = 0, y = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].color, "RED") == 0)         
        red[r++] = arr[i];
        else if (strcmp(arr[i].color, "BLUE") == 0)   
        blue[b++] = arr[i];
        else                             
        yellow[y++] = arr[i];
    }

    int idx = 0;
    for (int i = 0; i < r; i++) arr[idx++] = red[i];
    for (int i = 0; i < b; i++) arr[idx++] = blue[i];
    for (int i = 0; i < y; i++) arr[idx++] = yellow[i];

    free(red);
    free(blue);
    free(yellow);
}
int main(){
  Item arr[6] = {{1, "RED"}, {2, "BLUE"}, {3, "YELLOW"}, {4, "RED"}, {5, "BLUE"}, {6, "YELLOW"}};
  printf("Before sorting:\n");
    for(int i = 0; i < 6; i++){
        printf("%d %s\n", arr[i].number, arr[i].color);
    }
  sortByColorThreeBuckets(arr, 6);
  printf("After sorting:\n");
    for(int i = 0; i < 6; i++){
        printf("%d %s\n", arr[i].number, arr[i].color);
    }
}