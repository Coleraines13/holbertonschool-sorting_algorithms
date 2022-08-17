#include "sort.h"

/**
 * int_swap - swap two integers in an array
 * @current: thye first integer to swap
 * @next: the xecond integer to swap
 * Return: always
 */
void int_swap(int *current, int *next)
{
	int tmp;

	tmp = *current;
	*current = *next;
	*next = tmp;
}

/**
 * selection_sort - sorting the array of algos
 * @array: an array of integers
 * @size: the size of the array
 * Return: always 0
 */
void selection_sort(int *array, size_t size)
{
	int *temp;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		temp = array + i;
		for (j = i + 1; j < size; j++)
			temp = (array[j] < *temp) ? (array + j) : temp;

		if ((array + i) != temp)
		{
			int_swap(array + i, temp);
			print_array(array, size);
		}
	}
}
