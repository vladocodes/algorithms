"""
 * @file   binary_search.py
 * @author Vladimir Mijic
 * @date   26/03/2021
"""


def binarySearch(array, left, right, x):
    if left > right:
        return False

    mid = (left + right) // 2

    if array[mid] == x:
        return True
    elif array[mid] > x:
        return binarySearch(array, left, mid - 1, x)
    else:
        return binarySearch(array, mid + 1, right, x)



if __name__ == '__main__':
    arr = [75, 41, 92, 60, 2, 0, 39, 23, 10, 68]
    n = len(arr)
    print("Before:", arr)

    x = 23

    if binarySearch(arr, 0, n - 1, 23):
        print("The value %d exists in generated array!" % x)
    else:
        print("The value %d doesn't exist in generated array!", x)
