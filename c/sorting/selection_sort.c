//
// Created by Vladimir-HP on 29/12/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000
#define MIN -10000

// Fill array with random numbers from MIN to MAX
void fillArray(int array[], int n) {
    int i = 0;
    do {
        array[i] = rand() % (MAX - MIN + 1) + MIN;
        i++;
        n--;
    } while (n > 0);
}

void printArray(int array[], int n) {
    for (int i = 0; i < n; ++i)
        printf(" %d", array[i]);

    printf("\n\n");
}
// Swap two numbers using pointer
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int array[], int n) {
    int minIndex;
    for (int i = 0; i < n - 1; ++i) {
        minIndex = i;
        for (int j = i + 1; j < n; ++j)
            if (array[minIndex] > array[j])
                minIndex = j;

        swap(&array[minIndex], &array[i]);
    }
}



int main() {
    // Intializes random number generator
    srand(time(NULL));

    clock_t start, end;
    int n;
    printf("Number of elements in an array:");
    scanf("%d", &n);

    int array[n];
    fillArray(array, n);
    printf("Unsorted array:");
    printArray(array, n);


    start = clock();
    selectionSort(array, n);
    end = clock();

    double timeSpentInSec = (double) (end - start) / CLOCKS_PER_SEC;

    printf("Sorted array:");
    printArray(array, n);

    printf("Running time %.20fs.\n", timeSpentInSec);
    printf("Running time %.20fms.\n", timeSpentInSec * 1000.0);

    return 0;
}
