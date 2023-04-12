#include "search_algos.h"

/**
 *linear_search - a function to perform linear search
 *@array: pointer to the first element of the array
 *@size: number of elements in array
 *@value: the value to search for
 *Return: -1 on failure, the index on success
 */
int linear_search(int *array, size_t size, int value)
{
	size_t j = 0;

	if (array == NULL)
		return (-1);
	for (; j < size; j++)
	{
		printf("Value checked array[%lu] =[%d]\n", j, array[j]);
		if (array[j] == value)
			return (j);
	}

	return (-1);
}
