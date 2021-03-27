"""
 * @file   quick_sort.py
 * @author Vladimir Mijic
 * @date   27/03/2021
"""


def swap(array, i, j):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp


def partrition(array, lower, upper):
    pivot = array[upper]
    i = lower - 1

    for j in range(lower, upper):
        if array[j] < pivot:
            i += 1
            swap(array, i, j)

    i += 1
    swap(array, i, upper)
    return i


def quickSort(array, lower, upper):
    if lower < upper:
        pivot = partrition(array, lower, upper)
        quickSort(array, lower, pivot - 1)
        quickSort(array, pivot + 1, upper)


if __name__ == '__main__':
    arr = [75, 41, 92, 60, 2, 0, 39, 23, 10, 68]
    n = len(arr)
    print("Before:", arr)

    quickSort(arr, 0, n - 1)

    print("After:", arr)
