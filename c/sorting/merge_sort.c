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

void merge(int *array, int left, int mid, int right);

void mergeSort(int *array, int left, int right);


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
    mergeSort(array, 0, n - 1);
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


// Perform merge of segments
void merge(int *array, int left, int mid, int right) {
    int i, j, k;
    int *arr1, *arr2;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    arr1 = (int*)malloc(sizeof (int)*n1);
    arr2 = (int*)malloc(sizeof (int)*n2);

    for (i = 0; i < n1; i++)
        arr1[i] = array[left + i];

    for (j = 0; j < n2; j++)
        arr2[j] = array[mid + j + 1];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            array[k] = arr1[i];
            i++;
        } else {
            array[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = arr2[j];
        j++;
        k++;
    }

    free(arr1);
    free(arr2);
}


void mergeSort(int *array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}