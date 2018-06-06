#include "merge_sort_array.h"

template <class T>
void mergeSortArray<T>::merge_sort_asc() {
  merge_sort(list,length);
}

template <class T> void mergeSortArray<T>::merge_sort(T *arr, int size) {

  if (size < 2) // Base condition. List of 1 element is sorted
    return;

  // Create Left and Right sub arrays
  int mid = size / 2;
  T *L = new T[mid];
  T *R = new T[size - mid]; // Could be odd number of elements
  for (int i = 0; i < mid; i++)
    L[i] = arr[i];
  for (int i = mid; i < size; i++)
    R[i - mid] = arr[i];

  merge_sort(L, mid);                // Recursive merge sort left
  merge_sort(R, size - mid);         // Recursive merge sort right
  merge(arr, L, mid, R, size - mid); // Merge the sorted arrays
                                     // back into original array

  delete[] L;
  delete[] R;
}

template <class T>
void mergeSortArray<T>::merge(T *A, T *left, int left_size, T *right,
                              int right_size) {

  int i = 0; // Left sub-array index
  int j = 0; // Right sub-array index
  int k = 0; // Merged array (sorted) index

  // Until one of the left or right arrays is exhausted
  while (i < left_size && j < right_size)
    if (left[i] < right[j]) // Pick smaller element of left or right sub-array
      A[k++] = left[i++];
    else
      A[k++] = right[j++];

  // Attach leftover elements from either left or right sub-array
  // One of the two while loops will run
  while (i < left_size)
    A[k++] = left[i++];
  while (j < right_size)
    A[k++] = right[j++];
}
