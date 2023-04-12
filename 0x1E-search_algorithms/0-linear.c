#include "search_algos.h"

/**
 *linear_search - searches for a value in an array of integers
 *using the Linear search algorithm
 *@array: pointer to the first element of the array to search
 *@size: number of elements in array
 *@value: value to search for
 *Return: the index of the value, or -1 if not found
 */
int linear_search(int *array, size_t size, int value)
{
	int j;

	if (array == NULL)
		return (-1);

	for (j = 0; j < (int) size; j++)
	{
		printf("Value checked array[%u] =[%d]\n", j, array[j]);

		if (value == array[j])
			return (j);
	}

	return (-1);
}
