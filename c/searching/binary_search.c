//
// Created by Vladimir-HP on 27/02/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MIN -100


void fillArray(int array[], int n);

void swap(int *x, int *y);

void selectionSort(int array[], int n);

int binarySearch1(int array[], int l, int r, int x);

int binarySearch2(int array[], int l, int r, int x);


int main() {
    // Intializes random number generator
    srand(time(NULL));
    int n;
    printf("Number of elements in an array:");
    scanf("%d", &n);

    int array[n];
    fillArray(array, n);

    int x;
    printf("Enter the value that you are looking for:");
    scanf("%d", &x);


    // we need to ensure that the array is sorted before we start to search for an element
    selectionSort(array, n);


    if (binarySearch1(array, 0, n - 1, x)) {
        printf("The value %d exists in generated array!", x);
    } else {
        printf("The value %d doesn't exist in the generated array!", x);
    }

    exit(EXIT_SUCCESS);
}


void fillArray(int array[], int n) {
    for (int i = 0; i < n; ++i)
        array[i] = rand() % (MAX - MIN + 1) + MIN;
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


int binarySearch1(int array[], int l, int r, int x) {
    int mid;

    while (l <= r) {
        mid = l + (r - l) / 2;

        if (array[mid] == x) {
            return 1;
        } else if (array[mid] > x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return 0;
}


int binarySearch2(int array[], int l, int r, int x) {
    if (l > r) return 0;

    int mid = l + (r - l) / 2;

    if (array[mid] == x) {
        return 1;
    } else if (array[mid] > x) {
        return binarySearch2(array, l, mid - 1, x);
    } else {
        return binarySearch2(array, mid + 1, r, x);
    }
}
