//
// Created by oxvsys on 26/9/18.
//

#ifndef DAA_ASSIGNMENT_MERGE_H
#define DAA_ASSIGNMENT_MERGE_H

#endif //DAA_ASSIGNMENT_MERGE_H

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int size;

void mergeSort(int [], int, int, int);

void partition(int [], int, int);

void display(int []);


void partition(int list[], int low, int high) {
    int mid;

    if (low < high) {
        mid = (low + high) / 2;
        partition(list, low, mid);
        partition(list, mid + 1, high);
        mergeSort(list, low, mid, high);
    }
}

void mergeSort(int list[], int low, int mid, int high) {
    int i, mi, k, lo, temp[50];
//    display(list);
    lo = low;
    i = low;
    mi = mid + 1;
    while ((lo <= mid) && (mi <= high)) {
        if (list[lo] <= list[mi]) {
            temp[i] = list[lo];
            lo++;
        } else {
            temp[i] = list[mi];
            mi++;
        }
        i++;
    }
    if (lo > mid) {
        for (k = mi; k <= high; k++) {
            temp[i] = list[k];
            i++;
        }
    } else {
        for (k = lo; k <= mid; k++) {
            temp[i] = list[k];
            i++;
        }
    }

    for (k = low; k <= high; k++) {
        list[k] = temp[k];
    }
}

void display(int list[]) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf(" %d ", list[i]);
    }
    printf("]");
}