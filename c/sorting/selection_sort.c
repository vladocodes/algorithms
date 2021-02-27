//
// Created by Vladimir-HP on 29/12/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MIN -100


void fillArray(int array[], int n);

void printArray(int array[], int n);

void swap(int *x, int *y);

void selectionSort(int array[], int n);


int main() {
    // Intializes random number generator
    srand(time(NULL));

    clock_t start, end;
    int n;
    printf("Number of elements in an array:");
    scanf("%d", &n);

    int array[n];
    fillArray(array, n);
    printf("Unsorted array:\n");
    printArray(array, n);

    // Calculate the time taken by algorithm
    // Start measuring time
    start = clock();
    selectionSort(array, n);
    end = clock();
    // Stop measuring time and calculate the elapsed time
    double elapsedTime = (double) (end - start) / CLOCKS_PER_SEC;


    printf("Sorted array:\n");
    printArray(array, n);

    printf("Total time taken by CPU: %.20fs.\n", elapsedTime);              // time in seconds
    printf("Total time taken by CPU: %.20fms.\n", elapsedTime * 1000.0);    // time in milliseconds

    exit(EXIT_SUCCESS);
}


void fillArray(int array[], int n) {
    for (int i = 0; i < n; ++i)
        array[i] = rand() % (MAX - MIN + 1) + MIN;
}


void printArray(int array[], int n) {
    for (int i = 0; i < n; ++i)
        printf(" %d", array[i]);

    printf("\n\n");
}


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
