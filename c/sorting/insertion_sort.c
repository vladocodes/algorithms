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
    insertionSort(array, n);
    end = clock();

    double timeSpentInSec = (double) (end - start) / CLOCKS_PER_SEC;

    printf("Sorted array:");
    printArray(array, n);

    printf("Running time %.20fs.\n", timeSpentInSec);
    printf("Running time %.20fms.\n", timeSpentInSec * 1000.0);

    return 0;
}
