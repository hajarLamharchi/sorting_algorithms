#include "sort.h"

void TopDownMerge(int *b, int begin, int middle, int end, int *array);
void TopDownSplitSort(int *array, int *b, size_t size);
void TopDownSplitMerge(int *b, int begin, int end, int *array);
void cpyArray(int *array, int begin, int end, int *b);

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: the array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *b;

	if (!array || size < 2)
		return;
	b = malloc(sizeof(int) * size);
	if (b == NULL)
		return;
	TopDownSplitSort(array, b, size);
	free(b);
}
/**
 * TopDownSplitSort - sort using Merge sort
 * @array: array to sort
 * @b:  array to sort in
 * @size: size of array
 */
void TopDownSplitSort(int *array, int *b, size_t size)
{
	cpyArray(array, 0, (int)size, b);
	TopDownSplitMerge(array, 0, (int)size, b);
}
/**
 * TopDownSplitMerge - split array mergi and sort it
 * @b: original array
 * @begin: start index
 * @end: end index
 * @array: copie of array
 */
void TopDownSplitMerge(int *b, int begin, int end, int *array)
{
	int middle;

	if (end - begin == 1)
		return;
	middle = (end + begin) / 2;
	TopDownSplitMerge(array, begin, middle, b);
	TopDownSplitMerge(array, middle, end, b);
	TopDownMerge(b, begin, middle, end, array);
}
/**
 * TopDownMerge - merge array
 * @b: original array
 * @begin: start index
 * @middle: middle index
 * @end: end index
 * @array: copie of array
 */
void TopDownMerge(int *b, int begin, int middle, int end, int *array)
{
	int i = begin, j = middle, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + begin, middle - begin);
	printf("[right]: ");
	print_array(array + middle, end - middle);
	for (k = begin; k < end; k++)
	{
		if (i < middle && (j >= end || array[i] <= array[j]))
		{
			b[k] = array[i];
			i = i + 1;
		}
		else
		{
			b[k] = array[j];
			j = j + 1;
		}
	}
	printf("[Done]: ");
	print_array(b + begin, end - begin);
}
/**
 * cpyArray - copy array
 * @array: array
 * @begin: start index
 * @end: end index
 * @b: array to copie in
 */
void cpyArray(int *array, int begin, int end, int *b)
{
	int i;

	for (i = begin; i < end; i++)
	{
		b[i] = array[i];
	}
}
