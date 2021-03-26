"""
 * @file   bubble_sort.py
 * @author Vladimir Mijic
 * @date   26/03/2021
"""


def swap(array, i, j):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp


def bubbleSort(array):
    n = len(array)

    while True:
        sorted = True

        for i in range(1, n):
            if array[i] < array[i - 1]:
                swap(array, i, i - 1)
                sorted = False

        if sorted:
            break


if __name__ == '__main__':
    arr = [75, 41, 92, 60, 2, 0, 39, 23, 10, 68]
    print("Before:", arr)

    bubbleSort(arr)

    print("After:", arr)
