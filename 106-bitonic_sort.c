#include "sort.h"

void bitonic_sort(int *array, size_t size);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);

/**
 * bitonic_sort - Used to sort an array(ascending).
 *
 * @array: Refers to the array.
 * @size: Refers to the array's size.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}

/**
 * bitonic_seq - An array is turned into a bitonic sequence.
 *
 * @array: Refers to an array.
 * @size: Refers to the array's size.
 * @start:Refers to the start index in the array's sequence.
 * @seq: Refers to the bitonic sequence's size.
 * @flow: Shows the direction to be followed.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);

		print_array(array + start, seq);
		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_merge - Used to merge n sort a bitonic sequence in an array.
 *
 * @array: Refers to the array.
 * @size: Refers to the array's size.
 * @start: Refers to the start index of the array to be sorted.
 * @seq: The sequene's size that's to be sorted.
 * @flow: Shows the direction to be followed.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t index, jump = seq / 2;
	int tmp, *arr1, *arr2;

	if (seq > 1)
	{
		for (index = start; index < start + jump; index++)
		{
			arr1 = array + index;
			arr2 = array + index + jump;
			if ((flow == UP && array[index] > array[index + jump]) ||
					(flow == DOWN && array[index] < array[index + jump]))
			{
				tmp = *arr1;
				*arr1 = *arr2;
				*arr2 = tmp;
			}
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}
