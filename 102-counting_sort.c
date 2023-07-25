#include "sort.h"
#include <string.h>

/**
 * counting_sort -  sorts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: the array to sort
 * @size: size of the array
 *
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	int *count, *final;
	int max = array[0], i, j;
	
	if (!array || size < 2)
		return;
	for (i = 1; i < (int)size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;
	final = malloc(sizeof(int) * (size));
	if (final == NULL)
		return;
	for (i = 0; i < ((int)max + 1); i++)
	{
		count[i] = 0;
		for (j = 0; j < (int)size; j++)
		{
			if (i == array[j])
				count[i] += 1;
		}
	}
	for (i = 1; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (i = 0; i < (int)size; i++)
	{
		final[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = final[i];
	free(final);
	free(count);
}
