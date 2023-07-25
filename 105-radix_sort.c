#include "sort.h"

void radix_sort(int *array, size_t size);
int get_max(int *array, int size);
void radix_count(int *array, size_t size, int sign, int *buffer);

/**
 * radix_sort - Used to sort an array(ascending).
 *
 * @array: Refers to the array.
 * @size: Refers to the array's size.
 */
void radix_sort(int *array, size_t size)
{
	int max, sign, *buffer;

	if (array == NULL || size < 2)
		return;
	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	max = get_max(array, size);
	for (sign = 1; max / sign > 0; sign *= 10)
	{
		radix_count(array, size, sign, buffer);
		print_array(array, size);
	}
	free(buffer);
}

/**
 * get_max - Used to obtain an array's max value.
 *
 * @array: Refers to an array.
 * @size: Refers to the array's size.
 *
 * Return: The array's max value.
 */
int get_max(int *array, int size)
{
	int max, index;

	for (max = array[0], index = 1; index < size; index++)
	{
		if (array[index] > max)
			max = array[index];
	}

	return (max);
}

/**
 * radix_count - Looks for the significant digit.
 *
 * @array: Refers the array to be sorted from.
 * @size: Refers the array's size.
 * @sign: Represent the significant digit.
 * @buffer: The buffer to store the output.
 */
void radix_count(int *array, size_t size, int sign, int *buffer)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t indx;

	for (indx = 0; indx < size; indx++)
		count[(array[indx] / sign) % 10] += 1;
	for (indx = 0; indx < 10; indx++)
		count[indx] += count[indx - 1];
	for (indx = size - 1; (int)indx >= 0; indx--)
	{
		buffer[count[(array[indx] / sign) % 10] - 1] = array[indx];
		count[(array[indx] / sign) % 10] -= 1;
	}
	for (indx = 0; indx < size; indx++)
		array[indx] = buffer[indx];
}
