#include "search_algos.h"

/**
 *recursive_search - searches for a value in an array of
 *integers using the Binary search algorithm
 *
 *@array: input array
 *@size: size of the array
 *@value: value to search in
 *Return: index of the number
 */
int recursive_search(int *array, size_t size, int value)
{
	size_t half = size / 2;
	size_t i;

	/*Check if array is empty or size is 0 */
	if (array == NULL || size == 0)
		return (-1);

	/*Print the array */
	printf("Searching in array");

	for (i = 0; i < size; i++)
		printf("%s %d", (i == 0) ? ":" : ",", array[i]);

	printf("\n");

	/*If size is even, decrement half */
	if (half && size % 2 == 0)
		half--;

	/*If value is found, return the index */
	if (value == array[half])
		return ((int) half);

	/*If value is less than array[half], search left */
	if (value < array[half])
		return (recursive_search(array, half, value));

	/*If value is greater than array[half], search right */
	half++;

	return (recursive_search(array + half, size - half, value) + half);
}

/**
 *binary_search - calls to binary_search to return
 *the index of the number
 *
 *@array: input array
 *@size: size of the array
 *@value: value to search in
 *Return: index of the number
 */
int binary_search(int *array, size_t size, int value)
{
	int index;

	/*Call recursive_search to find the index */
	index = recursive_search(array, size, value);

	/*If index is found, but value is not equal to array[index], return -1 */
	if (index >= 0 && array[index] != value)
		return (-1);

	return (index);
}

/**
 *exponential_search - searches for a value in an array of
 *integers using the Exponential search algorithm
 *
 *@array: input array
 *@size: size of the array
 *@value: value to search in
 *Return: index of the number
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t index, next;
	int result;

	/*Check if array is empty */
	if (array == NULL)
		return (-1);

	/*If value is found at index 0, return 0 */
	if (array[0] == value)
		return (0);

	/*Set index to 1 */
	index = 1;

	/*While array[index] is less than value and index is less than size */
	while (array[index] < value && index < size)
	{
		printf("Value checked array[%d] =[%d]\n", (int) index, array[index]);
		index *= 2;
	}

	/*Set next to either index or size - 1 */
	next = (index >= size) ? (size - 1) : index;

	/*Divide index by 2 */
	index /= 2;

	printf("Value found between indexes[%d] and[%d]\n", (int) index, (int) next);

	/*Call binary_search to find the index */
	result = binary_search(array + index, (next + 1) - index, value);

	/*If result is found, add index to result */
	if (result >= 0)
		result += index;

	return (result);
}
