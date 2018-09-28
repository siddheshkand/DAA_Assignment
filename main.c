#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "merge.h"
#include "quick.h"

double cpu_time_used;
clock_t t;
//Global Array so we can use same array to check quick and merge sort runtime
int *arr = NULL;
//Global Array size
int size;

void generateRandom() {
    int i;
    srand(time(0));
    printf("Enter total number of random nos to generate elements:");
    scanf("%d", &size);
    arr = calloc((size_t) size, sizeof(int));
    printf("Randomly generated elements are :\n");
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 10000;
//        printf("%d ", arr[i]);
    }
    printf("\t\t\t\t\t\tRandom Nos generated");
}


void display(int list[]) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf(" %d ", list[i]);
    }
    printf("]");
}

void merge() {
    int i;
    // Start timer
    t = clock();
    partition(arr, 0, size - 1);
    // End timer
    t = clock() - t;
    //Generate time used
    cpu_time_used = ((double) t) / CLOCKS_PER_SEC;
    printf("\nAfter merge sort:\n");
    for (i = 0; i < size; i++) {
//        printf("%d   ", arr[i]);
    }
    printf("\t%f\t\n", cpu_time_used);
}

void quick() {
    t = clock() - t;
    quickSort(arr, 0, size - 1);
    cpu_time_used = ((double) t) / CLOCKS_PER_SEC;
    printf("\t%f\t\n", cpu_time_used);
}

int main() {
    int choice, num;


    while (1) {
        printf("\t\t\t\tEnter 0 to exit:\n");
        printf("\t\t\t\tEnter 1 to generate random nos:\n");
        printf("\t\t\t\tEnter 2 to merge sort analysis:\n");
        printf("\t\t\t\tEnter 3 to quick sort analysis:\n");
        printf("\t\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 0: {
                exit(0);
                break;
            }
            case 1: {
                generateRandom();
                break;
            }
            case 2: {
                merge();
                break;
            }
            case 3: {
                quick();
                break;
            }
            default:
                printf("Please Enter Valid Choice");
                break;
        }
    }

    return 0;
}
