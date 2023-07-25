#include "sort.h"

void heap_sort(int *array, size_t size);
void sift_down(int *array, size_t size, size_t base, size_t root);

/**
 * heap_sort - Used to sort an array(ascending).
 *
 * @array: Represents the array.
 * @size: Represents the array's size.
 */
void heap_sort(int *array, size_t size)
{
	int index, tmp, *arr;

	if (array == NULL || size < 2)
		return;

	for (index = (size / 2) - 1; index >= 0; index--)
		sift_down(array, size, size, index);

	for (index = size - 1; index > 0; index--)
	{
		arr = array + index;

		tmp = *array;
		*array = *arr;
		*arr = tmp;

		print_array(array, size);
		sift_down(array, size, index, 0);
	}
}

/**
 * sift_down - Converts from binary tree to binary heap.
 *
 * @array: Refers to the array.
 * @size: Refers to the array's size.
 * @base: Points to the index of the base.
 * @root: Refers to the binary tree's root.
 */
void sift_down(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large = 0;
	int *below, *above, tmp;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;
	below = array + root;
	above = array + large;

	if (large != root)
	{
		tmp = *below;
		*below = *above;
		*above = tmp;

		print_array(array, size);
		sift_down(array, size, base, large);
	}
}
