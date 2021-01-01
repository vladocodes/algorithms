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

void insertionSort(int array[], int n) {
    int i, j, temp;
    for (i = 1; i < n; ++i) {
        temp = array[i];
        for (j = i - 1; j >= 0; --j) {
            if (array[j] > temp)
                array[j + 1] = array[j];
            else
                break;
        }
        array[j + 1] = temp;
    }
}

void insertionSort2(int array[], int n) {
    int x, j;
    for (int i = 1; i < n; ++i) {
        x = array[i];
        j = i;
        while (j > 0 && array[j - 1] > x) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = x;
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
    insertionSort2(array, n);
    end = clock();
    // Stop measuring time and calculate the elapsed time
    double elapsedTime = (double) (end - start) / CLOCKS_PER_SEC;


    printf("Sorted array:\n");
    printArray(array, n);

    printf("Total time taken by CPU: %.20fs.\n", elapsedTime);              // time in seconds
    printf("Total time taken by CPU: %.20fms.\n", elapsedTime * 1000.0);    // time in milliseconds

    return 0;
}
