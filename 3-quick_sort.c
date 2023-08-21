#include "sort.h"
/**
 * lomuto_partition - Implements the Lomuto partition scheme
 * @array: Pointer to the array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * Return: Index of the pivot element after partition
 */
int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	
	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, high - low + 1); } } }
	int temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, high - low + 1);

	return (i + 1);
}
/**
 * quicksort - Recursive function to perform Quick Sort using Lomuto partition scheme
 * @array: Pointer to the array to be sorted
 * @low: Starting index of the current partition
 * @high: Ending index of the current partition
 */
void quicksort(int *array, int low, int high)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high);

		quicksort(array, low, pivot_index - 1);
		quicksort(array, pivot_index + 1, high); } }
/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quicksort(array, 0, size - 1); }
