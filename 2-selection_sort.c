#include "sort.h"

/**
 * selection_sort - An array is sorted in ascending way.
 *
 * @array: Represents the array.
 * @size: Represents the array's size.
 */
void selection_sort(int *array, size_t size)
{
	int *min, tmp;
	size_t index, jndex;

	if (array == NULL || size < 2)
		return;

	for (index = 0; index < size - 1; index++)
	{
		min = array + index;
		for (jndex = index + 1; jndex < size; jndex++)
			min = (array[jndex] < *min) ? (array + jndex) : min;
		if ((array + index) != min)
		{
			tmp = *(array + index);
			*(array + index) = *min;
			*min = tmp;
			print_array(array, size);
		}
	}
}
