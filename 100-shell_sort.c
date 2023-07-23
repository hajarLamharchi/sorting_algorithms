#include "sort.h"

/**
 * shell_sort -  sorts an array of integers in ascending order using
 * the Shell sort algorithm, using the Knuth sequence
 * @array: array to sort
 * @size: size of array
 *
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	int inter = 1;
	int i = 0;
	int tmp, val;

	if (!array || size < 2)
		return;

	while (inter < (int)size / 3)
	{
		inter = inter * 3 + 1;
	}
	while (inter > 0)
	{
		for (i = inter; i < (int)size; i++)
		{
			val = array[i];
			tmp = i;
			while (tmp > inter - 1 && array[tmp - inter] >= val)
			{
				array[tmp] = array[tmp - inter];
				tmp = tmp - inter;
			}
			array[tmp] = val;
		}
		inter = (inter - 1) / 3;
		print_array(array, size);
	}
}
