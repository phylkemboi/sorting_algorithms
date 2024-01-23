#include "sort.h"

/**
 * bubble_sort - Sort an array with buble sort algorithm
 * @array: Array that going to be sorted
 * @size: Size of array
 * Return: Nothing, just sort and print when swap
 */

void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t k, l;

	if (array == NULL || size == 0)
		return;

	for (k = 0; k < size; k++)
	{
		for (l = 0; l < size - 1; l++)
		{
			if (array[l] > array[l + 1])
			{
				tmp = array[l];
				array[l] = array[l + 1];
				array[l + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
