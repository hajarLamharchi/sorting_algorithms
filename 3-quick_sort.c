#include "sort.h"

int partition(int *arr, int lo, int li, size_t size);
void sort(int *array, int lo, int li, size_t size);
void swap(int *arr, int i, int j);
/**
 * quick_sort - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: the array to sort
 * @size: size of the array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort(array, 0, size - 1, size);


}
/**
 * sort - sort array using lomuto
 * @array:array to sort
 * @lo: first index
 * @li: last index
 * @size: size of array
 */
void sort(int *array, int lo, int li, size_t size)
{
	int p;

	if (lo < li)
	{
	p = partition(array, lo, li, size);
	sort(array, lo, p - 1, size);
	sort(array, p + 1, li, size);
	}
}
/**
 * partition - lomuto partition
 * @arr: array to sort
 * @lo: first index
 * @li: last index
 * @size: size of array
 *
 * Return: index of sorted element
 */
int partition(int *arr, int lo, int li, size_t size)
{
	int i = 0;
	int pivot = arr[li];
	int crrt = lo;

	for (i = lo; i < li; i++)
	{
		if (arr[i] < pivot)
		{
			crrt++;
			if (arr[crrt - 1] != arr[i])
			{
				swap(arr, crrt - 1, i);
				print_array(arr, size);
			}
		}
	}
	if (arr[crrt] != arr[li])
	{
		swap(arr, crrt, li);
		print_array(arr, size);
	}
	return (crrt);
}

/**
 * swap - swap 2 element in array
 * @arr: array to swap in
 * @i: first index
 * @j: second index
 *
 * Return : nothing
 */
void swap(int *arr, int i, int j)
{
	int aux = arr[i];

	arr[i] = arr[j];
	arr[j] = aux;
}
