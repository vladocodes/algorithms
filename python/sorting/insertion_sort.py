"""
 * @file   insertion_sort.py
 * @author Vladimir Mijic
 * @date   26/03/2021
"""


def insertionSort(array):
    n = len(array)

    for i in range(1, n):
        temp = array[i]
        j = i

        while j > 0 and array[j - 1] > temp:
            array[j] = array[j - 1]
            j -= 1

        array[j] = temp


if __name__ == '__main__':
    arr = [75, 41, 92, 60, 2, 0, 39, 23, 10, 68]
    print("Before:", arr)

    insertionSort(arr)

    print("After:", arr)
