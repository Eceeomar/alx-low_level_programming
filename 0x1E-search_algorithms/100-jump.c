#include "search_algos.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * jump_search - Searches for a value in a sorted array of integers using the Jump search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: First index where value is located, or -1 if value is not present in array or if array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	int step, prev = 0;
	int i;

	if (array == NULL)
		return (-1);

	step = (int)sqrt(size);

	while (array[min(step, size) - 1] < value)
	{
		prev = step;
		step += (int)sqrt(size);
		if (prev >= size)
			return (-1);
	}

	while (array[prev] < value)
	{
		prev++;
		if (prev == min(step, size))
			return (-1);
	}

	if (array[prev] == value)
		return (prev);

	return (-1);
}

/**
 * min - Computes the minimum of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: Minimum of two integers
 */
int min(int a, int b)
{
	return (a < b ? a : b);
}
