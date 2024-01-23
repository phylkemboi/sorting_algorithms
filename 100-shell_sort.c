#include "sort.h"
/**
 * shell_sort -Sort an array using shell_sort algorithm
 * @array: array
 * @size: size of the array
 * Return: NULL
 **/

void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, k, l;
	int temp;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (k = gap; k < size; k++)
		{
			temp = array[k];
			l = k;
			while (l >= gap && array[l - gap] > temp)
			{
				array[l] = array[l - gap];
				l -= gap;
			}
			array[l] = temp;
		}
		print_array(array, size);
		gap /= 3;
	}
}
