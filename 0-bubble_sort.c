#include "sort.h"

/**
 * bubble_sort - An array of integers is sorted from small to large.
 *
 * @array: Refers to the array been sorted
 * @size: Represents the array's size
 */
void bubble_sort(int *array, size_t size)
{
	size_t index, len = size;
	bool bubble = false;
	int tmp;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (index = 0; index < len - 1; index++)
		{
			if (array[index] > array[index + 1])
			{
				tmp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = tmp;
				print_array(array, size);
				bubble = false;
			}
		}
		len--;
	}
}
