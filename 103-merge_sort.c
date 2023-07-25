#include "sort.h"

void merge_sort(int *array, size_t size);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);

/**
 * merge_sort - Used to sort an array.
 *
 * @array: Represents the array
 * @size: Represents the array's size.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);
	free(buffer);
}

/**
 * merge_sort_recursive - Executes the algo for merging n sorting.
 *
 * @subarr: Represents a sub array.
 * @buff: Refers to the buffer.
 * @front: The sub array's front index.
 * @back: The sub array's back index..
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid, index, jndex, kndex = 0;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);

		printf("Merging...\n[left]: ");
		print_array(subarr + front, mid - front);

		printf("[right]: ");
		print_array(subarr + mid, back - mid);

		for (index = front, jndex = mid; index < mid && jndex < back; kndex++)
			buff[kndex] = (subarr[index] < subarr[jndex]) ?
				subarr[index++] : subarr[jndex++];
		for (; index < mid; index++)
			buff[kndex++] = subarr[index];
		for (; jndex < back; jndex++)
			buff[kndex++] = subarr[jndex];
		for (index = front, kndex = 0; index < back; index++)
			subarr[index] = buff[kndex++];

		printf("[Done]: ");
		print_array(subarr + front, back - front);
	}
}
