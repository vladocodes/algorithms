"""
 * @file   merge_sort.py
 * @author Vladimir Mijic
 * @date   27/03/2021
"""


def merge(array, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid

    arr1 = [0] * n1
    arr2 = [0] * n2

    for i in range(0, n1):
        arr1[i] = array[left + i]
    for j in range(0, n2):
        arr2[j] = array[mid + j + 1]

    i = 0
    j = 0
    k = left

    while i < n1 and j < n2:
        if arr1[i] <= arr2[j]:
            array[k] = arr1[i]
            i += 1
        else:
            array[k] = arr2[j]
            j += 1
        k += 1

    while i < n1:
        array[k] = arr1[i]
        i += 1
        k += 1

    while j < n2:
        array[k] = arr2[j]
        j += 1
        k += 1


def mergeSort(array, left, right):
    if left < right:
        mid = (right + left) // 2

        mergeSort(array, left, mid)
        mergeSort(array, mid + 1, right)

        merge(array, left, mid, right)


if __name__ == '__main__':
    arr = [75, 41, 92, 60, 2, 0, 39, 23, 10, 68]
    n = len(arr)
    print("Before:", arr)

    mergeSort(arr, 0, n - 1)

    print("After:", arr)
