"""
 * @file   selection_sort.py
 * @author Vladimir Mijic
 * @date   26/03/2021
"""


def swap(array, i, j):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp


def selectionSort(array):
    n = len(array)

    for i in range(0, n - 1):
        minIndx = i
        for j in range(i + 1, n):
            if array[minIndx] > array[j]:
                minIndx = j

        swap(arr, i, minIndx)


if __name__ == '__main__':
    arr = [75, 41, 92, 60, 2, 0, 39, 23, 10, 68]
    print("Before:", arr)

    selectionSort(arr)

    print("After:", arr)
