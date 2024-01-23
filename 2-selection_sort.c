#include "sort.h"

/**
 * locate_min - Locatin the min From Current index in the array
 * @array: The Array to be Searched
 * @index: Starting Index of The Search
 * @size: The Size of The Array
 * Return: (int) index of min if found or
 * same given index if index is the min
 */

int locate_min(int *array, int index, size_t size)
{
	int min, idx_min;
	int k;

	min = array[index];
	idx_min = index;
	for (k = index; k < (int)size; k++)
	{
		if (array[k] < min)
		{
			min = array[k];
			idx_min = k;
		}
	}
	if (idx_min == index)
		return (-1);
	return (idx_min);
}


/**
 * selection_sort - Implementation of selection Sort Algrithme
 * @array: Array to sort type int *
 * @size: The Size of The Given Array
 *
 * Return: (Void) Sorted Array
 */
void selection_sort(int *array, size_t size)
{
	int k;
	int min, tmp;

	for (k = 0; k < (int)size; k++)
	{
		min = locate_min(array, k, size);
		if (min != -1)
		{
			tmp = array[k];
			array[k] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
