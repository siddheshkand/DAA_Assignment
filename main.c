#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "merge.h"
double cpu_time_used;
clock_t t;

void merge() {
    srand(time(0));
    int i;
    int *a = NULL;
    printf("Enter total number of random nos to generate elements:");
    scanf("%d", &size);
    a = calloc((size_t) size, sizeof(int));
    printf("Randomly generated elements are :\n");
    for (i = 0; i < size; i++) {
        a[i] = rand() % 10000;
        printf("%d ", a[i]);
    }
    // Start timer
    t = clock();
    partition(a, 0, size - 1);
    // End timer
    t = clock() - t;
    //Generate time used
    cpu_time_used = ((double) t) / CLOCKS_PER_SEC;
    printf("\nAfter merge sort:\n");
    for (i = 0; i < size; i++) {
//        printf("%d   ", a[i]);
    }
    printf("\t%f\t\n", cpu_time_used);
}

void quick() {

}

int main() {
    int choice, num;
    printf("\t\t\t\tEnter 0 to exit:\n");
    printf("\t\t\t\tEnter 1 to merge sort analysis:\n");
    printf("\t\t\t\tEnter 2 to quick sort analysis:\n");
    printf("\t\t\t\t\tEnter your choice: ");
    scanf("%d", &choice);

    while (1) {
        switch (choice) {
            case 0: {
                exit(0);
            }
            case 1: {
                merge();
            }
            case 3: {
                quick();
            }
            default:
                break;
        }
    }

    return 0;
}
