#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using the bubble sort
 * @array: the array to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j;
	int temp;
	bool swapped = false;

	if (size < 2)
		return;
	do
	{
		swapped = false;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swapped = true;
			}
		}
		i++;
	}
	while (swapped == true);
}
