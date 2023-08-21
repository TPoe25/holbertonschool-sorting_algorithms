#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_recursive(array, 0, size - 1, size);
}

/**
 * quicksort_recursive - Recursive helper function for quick_sort
 * @array: Pointer to the array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = lomuto_partition(array, low, high, size);
        quicksort_recursive(array, low, pivot - 1, size);
        quicksort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * lomuto_partition - Lomuto partition scheme for quick_sort
 * @array: Pointer to the array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 *
 * Return: Index of the pivot element after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                /* Print the array after each swap */
                print_array(array, size);
            }
        }
    }

    if (array[i + 1] != array[high])
    {
        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        /* Print the array after each swap */
        print_array(array, size);
    }

    return (i + 1);
}

