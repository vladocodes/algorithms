//
// Created by Vladimir-HP on 29/12/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

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

void bubbleSort(int array[], int n) {
    bool sortiran = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                sortiran = false;
            }
        }
        if (sortiran) break;
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
    printf("Unsorted array:\n");
    printArray(array, n);

    // Calculate the time taken by algorithm
    // Start measuring time
    start = clock();
    bubbleSort(array, n);
    end = clock();
    // Stop measuring time and calculate the elapsed time
    double elapsedTime = (double) (end - start) / CLOCKS_PER_SEC;


    printf("Sorted array:\n");
    printArray(array, n);

    printf("Total time taken by CPU: %.20fs.\n", elapsedTime);              // time in seconds
    printf("Total time taken by CPU: %.20fms.\n", elapsedTime * 1000.0);    // time in milliseconds
    return 0;
}



