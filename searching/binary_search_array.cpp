#include "binary_search_array.h"

template <class T> int binarySearchArray<T>::binary_search(const T &item) {
  // Binary search iterative implementation
  // Return index of item if found, -1 otherwise

  // List could be unsorted
  if (!this->is_sorted())
    this->quick_sort();

  int start = 0;
  int end = length - 1;

  while (start <= end) {

    int mid = start + (end - start) / 2;

    if (item == list[mid])
      return mid;              // Item found, return location
    else if (item < list[mid]) // Search left sub-array
      end = mid - 1;
    else // Search right sub-array
      start = mid + 1;
  }
  return -1; // If item not found
}

template <class T> int binarySearchArray<T>::binary_search_rec(const T &item) {
  if (!this->is_sorted())
    this->quick_sort();
  rec_binary_search(0, length - 1, item);
}

template <class T>
int binarySearchArray<T>::rec_binary_search(int start, int end, const T &item) {
  if (start > end) // Item not found,exit
    return -1;
  int mid = start + (end - start) / 2;
  if (item == list[mid]) // Item found, return location, exit
    return mid;
  else if (item < list[mid]) // Binary search left sub-array
    rec_binary_search(start, mid - 1, item);
  else
    rec_binary_search(mid + 1, end, item); // Binary search right sub-array
}
