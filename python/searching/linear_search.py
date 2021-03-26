"""
 * @file   linear_search.py
 * @author Vladimir Mijic
 * @date   26/03/2021
"""


def linearSearch(array, x):
    n = len(array)

    for i in range(0, n):
        if array[i] == x:
            return True

    return False


if __name__ == '__main__':
    arr = [75, 41, 92, 60, 2, 0, 39, 23, 10, 68]
    print("Before:", arr)

    x = 23

    if linearSearch(arr, 23):
        print("The value %d exists in generated array!" % x)
    else:
        print("The value %d doesn't exist in generated array!", x)
