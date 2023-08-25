#include "sort.h"

/**
 * quick_sort - Sorts an array of ints in ascending order using Quick sort alg
 * @array: The array to be sorted
 * @size: The number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}
/**
 * partition - Partitions the array for quick sort.
 * @array: The array to be partitioned.
 * @low: Lower index of the partition.
 * @high: Higher index of the partition.
 * @size: Size of the array.
 * Return: Index of the Pivot.
 */
int partition(int *array, int low, int high, size_t size)
{
	int i = low - 1, j = low;
	int pivot = array[high], aux = 0;

	for (; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size); } } }
	if (array[i + 1] != array[high])
	{
		aux = array[i + 1];
		array[i + 1] = array[high];
		array[high] = aux;
		print_array(array, size); }
	return (i + 1); }
/**
 * quick_sort_recursive - Implements the quick sort algorithm recursively.
 * @array: Array to be sorted.
 * @low: Lower index of the array to sort.
 * @high: Higher index of the array to sort.
 * @size: Size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size); } }

