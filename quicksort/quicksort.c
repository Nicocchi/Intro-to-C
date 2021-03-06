#include <stdio.h>
#include "lib.h"

/*
    Implement the Quicksort algorithm. You'll likely want to re-use the
    `swap` function you implemented in the pointers module (which is
    already being included for you in this file).

    The `low` and `high` parameters indicate the lowest and highest indices
    of the array that is getting passed in. This is necessary because the
    function is being passed a pointer to the array, not the contents of the
    array. We can't easily figure out the length of the array through the
    pointer, so the function receives the highest and lowest indices as
    parameters to circumvent this issue.

    Do not just use the `qsort` function from the standard library.
*/
void quicksort(int *arr, int low, int high)
{
  if (low < high)
  {
    // Parition the index
    int pi = partition(arr, low, high);

    // Then separately sort elements before partition and after
    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
  }
}

/* Takes the last element as pivot, places
   the pivot element at its correct position in sorted
   array and places all smaller to left and greater to right
*/
int partition (int arr[], int low, int high)
{
  // Pivot
  int pivot = arr[high];
  // Index of smaller element
  int i = (low -1);

  for (int j = low; j <= high - 1; j++)
  {
    // If current element is smaller than or equal to, increment
    // index of smaller element
    if (arr[j] <= pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

#ifndef TESTING
int main(void)
{
    int arr1[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    quicksort(arr1, 0, n-1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }

    printf("\n");

    return 0;
}
#endif
