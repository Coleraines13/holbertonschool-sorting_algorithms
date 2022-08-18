#include "sort.h"

void int_swap(int *current, int *next);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * int_swap - swaps two integers in an array
 * @current: the first integer to swap
 * @next: the second integer to swap
 * Return: alwasy 0
 */

void int_swap(int *current, int *next)
{
	int tmp;

	tmp = *current;
	*current = *next;
	*next = tmp;
}

/**
 * lomuto_partition - order a subset of an array
 * @array: the array of integers
 * @size: the size of the array
 * @left: the starting index of the subset to order
 * @right: the ending index of the subset to order
 * Return: always 0
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				int_swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		int_swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - implement the quicksort algorithm through recursion
 * @array: an array of integers to sort
 * @size: the size of the array
 * @left: the starting index of the array partition to order
 * @right: the ending index of the array partition to order
 * Return: always 0
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - sort an array of integers
 * @array: an array of integer
 * @size: the size of the array
 * Return: always 0
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
