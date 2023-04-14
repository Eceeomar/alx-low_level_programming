#include "search_algos.h"

/**
 *recursive_binary_search - searches for a value in a sorted array of
 *integers using the binary search algorithm recursively
 *
 *@array: pointer to the first element of the array
 *@low: the lower bound of the search range
 *@high: the upper bound of the search range
 *@value: value to search for
 *
 *Return: index of the value in the array, or -1 if not found
 */
int recursive_binary_search(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	if (low > high)
		return (-1);

	mid = (low + high) / 2;

	if (array[mid] == value)
		return ((int) mid);

	if (value < array[mid])
		return (recursive_binary_search(array, low, mid - 1, value));

	return (recursive_binary_search(array, mid + 1, high, value));
}

/**
 *binary_search - searches for a value in a sorted array of
 *integers using the binary search algorithm
 *
 *@array: pointer to the first element of the array
 *@size: the number of elements in the array
 *@value: value to search for
 *
 *Return: index of the value in the array, or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (recursive_binary_search(array, 0, size - 1, value));
}

/**
 *exponential_search - searches for a value in a sorted array of
 *integers using the exponential search algorithm
 *
 *@array: pointer to the first element of the array
 *@size: the number of elements in the array
 *@value: value to search for
 *
 *Return: index of the value in the array, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;

	if (array == NULL || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%ld] =[%d]\n", bound, array[bound]);
		bound *= 2;
	}

	printf("Value found between indexes[%ld] and[%ld]\n", bound / 2, bound - 1);

	return (binary_search(array + bound / 2, bound < size ? bound : size, value));
}
