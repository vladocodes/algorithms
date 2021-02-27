//
// Created by Vladimir-HP on 27/02/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MIN -100


void fillArray(int array[], int n);

int linearSearch(int array[], int n, int x);


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

    if (linearSearch(array, n, x)) {
        printf("The value %d exists in generated array!", x);
    } else {
        printf("The value %d doesn't exist in generated array!", x);
    }

    exit(EXIT_SUCCESS);
}


void fillArray(int array[], int n) {
    for (int i = 0; i < n; ++i)
        array[i] = rand() % (MAX - MIN + 1) + MIN;
}


int linearSearch(int array[], int n, int x) {
    for (int i = 0; i < n; ++i)
        if (array[i] == x) return 1;

    return 0;
}
