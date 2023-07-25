#include "sort.h"

void quick_sort(int *array, size_t size);
void lomuto_sort(int *array, size_t size, int left, int right);
int lomuto_partition(int *array, size_t size, int left, int right);
void swap_ints(int *a, int *b);

/**
 * quick_sort - An array is sorted in ascending way.
 *
 * @array: Represents the array.
 * @size: Represnt's the array's size.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

/**
 * lomuto_sort - Used to execute the quicksort algorithm.
 *
 * @array: Represents the array.
 * @size: Represnt's the size's array.
 * @left: The start point to sort from.
 * @right: The end point.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * lomuto_partition - Sorts a subset of the array.
 *
 * @array: Represnts the array.
 * @size: Represents the arry's size.
 * @left: The start point.
 * @right: The end point.
 *
 * Return: The final index of the subset.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;

	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * swap_ints - Two integers in an array are swaped.
 *
 * @a: 1st integer to be swaped.
 * @b: 2nd integer to be swaped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
