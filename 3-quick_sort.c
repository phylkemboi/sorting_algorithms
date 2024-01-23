#include "sort.h"

/**
 * swap - swap two int
 * @a: int
 * @b: int
 * Return: (void) Swaped int
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * partition - Partition an array and using pivot
 * @array: Array
 * @low: int
 * @high: int
 * @size: size of array (size_t)
 * Return: index of pivote (int)
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int m = low - 1, p;

	for (p = low; p <= high; p++)
	{
		if (array[p] <= pivot)
		{
			m++;
			if (m != p)
			{
				swap(&array[m], &array[p]);
				print_array(array, size);
			}
		}
	}
	return (m);
}
/**
 * lomuto_qsort - Sorting Recursively an Array
 * @array: Array to be sorted
 * @low: The lowest value of the array
 * @high: highest value of the array
 * @size: Size of The Array
 * Return: void
 */
void lomuto_qsort(int *array, int low, int high, size_t size)
{
	int k;

	if (low < high)
	{
		k = partition(array, low, high, size);
		lomuto_qsort(array, low, k - 1, size);
		lomuto_qsort(array, k + 1, high, size);
	}
}
/**
 * quick_sort - Quick Sort Algorithme using lomuto partition
 * @array: Array to sort
 * @size: Size of The Array
 * Return: Sorted Array (void)
 */
void quick_sort(int *array, size_t size)
{
	lomuto_qsort(array, 0, size - 1, size);
}
