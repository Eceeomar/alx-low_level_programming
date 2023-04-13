#include <stdio.h>
#include <stdlib.h>

/*
 * linear_search() - Searches for a value in an array of integers using the Linear search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Returns the first index where value is located. If value is not present in array or if array is NULL,
 * returns -1
 */
int linear_search(int *array, size_t size, int value) {
    // Check if array is NULL
    if (array == NULL) {
        return -1;
    }

    // Iterate through array and compare each element to value
    for (int i = 0; i < size; i++) {
        printf("Comparing %d to %d\n", array[i], value);
        if (array[i] == value) {
            return i;
        }
    }

    // If value is not present in array, return -1
    return -1;
}
